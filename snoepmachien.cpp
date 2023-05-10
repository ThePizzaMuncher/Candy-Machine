#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "snack.h"

#define string std::string
#define cin std::cin

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos{0,0};

using namespace fmt;

// 
snacc snaccs[3][3] = {
	{snacc("M&Ms", 21, 2.2), snacc("Snickers", 22, 1.5), snacc("Twix", 23, 1.5)},
	{snacc("Bounty", 31, 1.5), snacc("Mars", 32, 1), snacc("KitKat", 33, 1.2)},
	{snacc("Milka", 41, 2.5), snacc("Lion", 42, 2), snacc("Croky", 43, 2)}
};

void choose();
int payment(int &i, int &j, int &k);
void delivery(int &j, int &k, bool l);
void prePrint();
void cMove(short offsetY);
void cMove(short offsetX, short offsetY);
void setPos(short x, short y);
void setOut();

void clearScreen() { setPos(45,6); print("{: <28}", " "); cMove(1); print("{: <28}", " "); setPos(45,6); }


int main()
{
	prePrint();
	while (true)
	{
		setPos(45,6);
		print("Maak uw keuze...");
		choose();
	}
	return 0;
}

void choose()
{
	// char c stores the user’s input, int i is the int that those make
	char c[2]; int i{0};
	while (c[0] != '2' && c[0] != '3' && c[0] != '4') {
		c[0] = getch();
	}
	clearScreen();
	print("{}", c);
	while (c[1] != '1' && c[1] != '2' && c[1] != '3') {
		c[1] = getch();
	} setPos(45,6); i = (c[0] - '0') * 10 + (c[1] - '0');
	int j{c[0] - '0'}, k{c[1] - '0'}; j -= 2; --k;
	int reTurn = payment(i, j, k);
	if (reTurn == 2) return;
	if (reTurn == 1) delivery(j, k, true);
	else delivery(j, k, false);
}

int payment(int &i, int &j, int &k)
{
	// 33|€1.20┃1=¢10|2=¢20|3=¢50
	// €0.00   ┃4=€1|5=€2|6=stop
	print("{: <8}┃{: <19}", format("{}|{}", i, snaccs[j][k].pricestr), "1=10¢|2=20¢|3=50¢"); cMove(1);
	print("€0,00   ┃{: <19}", "4=€1|5=€2|0=stop");

	double paid{0.00};
	while (paid < snaccs[j][k].price) {
no:
		setPos(45,7);
		int x{getch()};
		switch (x) {
			case 49:
				paid += 0.1;
			break; case 50:
				paid += 0.2;
			break; case 51:
				paid += 0.5;
			break; case 52:
				paid += 1;
			break; case 53:
				paid += 2;
			break; case 48:
				clearScreen();
				print("Afgebroken"); cMove(1); print("Tot ziens");
				Sleep(3000);
				clearScreen();
				return 2;
			break; default:
				goto no;
		}
		print("€{},{:.0f}", int(paid), (paid - floor(paid)) * 100);
	};
	if (paid > snaccs[j][k].price) {
		setPos(44,25);
		double diff = paid - snaccs[j][k].price;
		print("{}", format("{: ^32}", format("│{:.0},{:.0f}│", floor(diff), (diff - floor(diff)) * 100)));
		return 1;
	}
	return 0;
}

void delivery(int &j, int &k, bool l)
{
	clearScreen();
	print("Neem uw {}", snaccs[j][k].name); if (l == true) print(" en wisselstacks"); cMove(1);
	print("(Druk op toets op te nemen)");

	setPos(3,34);
	print("{: ^36}", snaccs[j][k].name); cMove(1);
	print("{: ^36}", snaccs[j][k].name); cMove(1);

	cin.clear();
	system("pause > nul");
	
	clearScreen();
	print("Tot ziens!");
	setPos(3,34);
	print("{: ^35}", " "); cMove(1);
	print("{: ^35}", " ");
	setPos(44,25);
	print("{: ^32}", "│    │");
}

void prePrint()
{
	system("cls");

	print("╔{:═>79}", "╗"); cMove(1);
	for (int i{0}; i < 40; ++i, cMove(1))
		print("║{: >79}", "║");
	print("╚{:═>79}", "╝");

	setPos(2,1);
	print("┏{:━>38}", "┓");
	for (cMove(1); pos.Y < 30; cMove(1))
		print("┃{: >38}", "┃");
	print("┗{:━>38}", "┛");
	
	setPos(3,2);
	for (int i{0}; i < 3; ++i) {
		for (int j{0}; j < 3; ++j)
			print("{:^12}", snaccs[i][j].name); cMove(1);
		print("┌{0:─>11}┌{0:─>11}┌{0:─>11}", "┐"); cMove(1);
		for(int j{0}; j < 3; ++j)
			print("│{:<5}{:>5}│", snaccs[i][j].option, snaccs[i][j].pricestr); cMove(1);
		print("└{0:─>11}└{0:─>11}└{0:─>11}", "┘"); if (i == 0 || i == 1) cMove(2);
	}
	setPos(44,5);
	print("┌{:─>30}", "┐"); cMove(1);
	print("│{: >30}", "│"); cMove(1);
	print("│{: >30}", "│"); cMove(1);
	print("└{:─>30}", "┘"); cMove(1,-1);
	// for (char c{'a'}; c <= 'z'; ++c) print("{}", c);
	// for (int i{0}; i < 3; ++i) print("{}", i);

	cMove(-1,3);
	for (int i{1}; pos.Y < 15; cMove(2)) {
		string cell[3];
		for (int k{0}; k < 3; ++k, ++i)
			cell[k] = format("{: ^4}", i);
		print("{: ^32}", format("{}", join(cell, "")));
	} print("{: ^32}", 0);
	
	cMove(2);
	print("{: ^32}", "┌─┐┌┐"); cMove(1);
	print("{: ^32}", "└─┘││"); cMove(1);
	print("{: ^32}", "   └┘"); cMove(4);

	print("{: ^32}", "┌────┐"); cMove(1);
	print("{: ^32}", "│    │"); cMove(1);
	print("{: ^32}", "└────┘");

	setPos(2,32);
	print("╔{:═>38}", "╗");
	for (cMove(1); pos.Y < 37; cMove(1))
		print("║{: >38}", "║");
	print("╚{:═>38}", "╝");
}



// These functions control the cursor
void cMove(short offsetY)
{
	pos.Y += offsetY;
	SetConsoleCursorPosition(hOut, pos);
} void cMove(short offsetX, short offsetY)
{
	pos.X += offsetX;
	pos.Y += offsetY;
	SetConsoleCursorPosition(hOut, pos);
}

void setPos(short x, short y)
{
	pos = {x,y};
	SetConsoleCursorPosition(hOut, pos);
}

// This function prepares the output stuff so that it works with the special characters and so that the cursor can be manipulated
void setOut()
{
	DWORD consoleMode;
	GetConsoleMode( hOut , &consoleMode);
	consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode( hOut , consoleMode );
	std::system("color 0f");
	setPos(0,0);
}

// The notes originally from near the start
/* Basically my notepad. Don’t judge me.
	Here be box drawing characters, for mine own copying convenience
	⎸⎹ ␣ ─ ━ │ ┃ ┌ ┍ ┎ ┏ ┐ ┑ ┒ ┓ └ ┕ ┖ ┗ ┘ ┙ ┚ ┛

	├ ┝ ┞ ┟ ┠ ┡ ┢ ┣ ┤ ┥ ┦ ┧ ┨ ┩ ┪ ┫

	┬ ┭ ┮ ┯ ┰ ┱ ┲ ┳ ┴ ┵ ┶ ┷ ┸ ┹ ┺ ┻

	┼ ┽ ┾ ┿ ╀ ╁ ╂ ╃ ╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋

	╭ ╮ ╯ ╰ ╱ ╲ ╳

	╴ ╵ ╶ ╷ ╸ ╹ ╺ ╻ ╼ ╽ ╾ ╿

"
	  Snickers
	┌──────────┐
	│22   €1,50│
	└──────────┘
"
*/