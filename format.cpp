#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define setPos SetConsoleCursorPosition

/* bool boem()
{
	return;
} */

int main()
{
	/* system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos{2, 1}; */
	
/* 	double a{.1}, b{1}, c{1.1}, d{10};
	fmt::print("a: {:.0f}; b: {:.0f}, c: {:.0f}; d: {:.0f}\n", a, b, c, d);
	fmt::print("a: {:.1f}; b: {:.1f}; c: {:.1f}; d: {:.1f}\n", a, b, c, d);
	fmt::print("a: {:.2f}; b: {:.2f}; c: {:.2f}; d: {:.2f}\n", a, b, c, d);
	// fmt::print("{:.0f},{:.0f}\n\n", a, (a - floor(a)) * 100);
	fmt::print("{.0f}", a); */

	int c = getch();
	fmt::print("{}\n", c);

/* 	char input; int i{0};
	while (!_kbhit()) {
		fmt::print("{}\n", ++i);
		Sleep(2000);
		fmt::print("{}\n", ++i);
		Sleep(2000);
	} */

	/* fmt::print("╔{:═>80}", "╗\n");
	for (int i{0}; i < 40; ++i)
		fmt::print("║{: >80}", "║\n");
	fmt::print("╚{:═>79}", "╝");

	SetConsoleCursorPosition(hConsole, pos);
	fmt::print("┏{:━>38}", "┓\n");
	for (++pos.Y, SetConsoleCursorPosition(hConsole, pos); pos.Y < 16; ++pos.Y, SetConsoleCursorPosition(hConsole, pos))
		fmt::print("┃{: >38}", "┃\n");
	fmt::print("┗{:━>38}", "┛\n"); */
	
/* 
	// short x{40}, y{0};
	SetConsoleCursorPosition(hConsole, pos);
	
	// Maak keuze
	fmt::print("┌{:─>30}", "┐"); ++pos.Y; SetConsoleCursorPosition(hConsole, pos);
	fmt::print("│{: >30}", "│"); ++pos.Y; SetConsoleCursorPosition(hConsole, pos);
	fmt::print("└{:─>30}", "┘"); --pos.Y; ++pos.X; SetConsoleCursorPosition(hConsole, pos);
	for (char c{'a'}; c <= 'z'; ++c) fmt::print("{}", c);
	for (int i{0}; i < 3; ++i) fmt::print("{}", i);

	// ++pos.Y;
	--pos.X;
	pos.Y += 3;
	SetConsoleCursorPosition(hConsole, pos);
	for (int i{1}; pos.Y < 9; pos.Y += 2, SetConsoleCursorPosition(hConsole, pos)) {
		// fmt::print("{ ^32}", "{: ^4}{: ^4}{: ^4}{: ^4}", i, i + 1, i + 2);	obsolete
		std::string cell[3];
	// std::string row;
		for (int k{0}; k < 3; ++k, ++i)
			cell[k] = fmt::format("{: ^4}", i);
			// row += fmt::format("{: ^4}", i);
		fmt::print("{: ^32}", fmt::format("{}", fmt::join(cell, "")));
		// fmt::print("{:^31}", row);
	}
	fmt::print("{: ^32}", 0);
	
	// fmt::print(fmt::emphasis::bold, "Maak keuze");
 */	
/*
	
*/
/*
	═ ║ ╔ ╗ ╚ ╝ ╠ ╣ ╦ ╩ ╬ 
	━ ┃ ┏ ┓ ┗ ┛ ┣ ┫ ┳ ┻ ╋ 
	─ │ ┌  └ ┘ ├ ┤ ┬ ┴ ┼
*/

/* 
	std::string s[]{"een", "twee", "driiee"};
	fmt::print("|{:^8}|\n", fmt::join(s, "|"));
	fmt::print("┌{:─>{}}\n", "┐", 26);
	fmt::print("┌{:─>26}", "┐");
	std::string e = "\n─\n";
	fmt::print("{}", e);
	fmt::print("╭╮");
*/
/*
	std::string arr[7][7];
	arr[0][0] = "╭", arr[0][6] = "╮";
	for (int i{1}; i < 6; ++i)
		{ if (i % 2 != 0) arr[0][i] = "─"; else arr[0][i] = "┬"; }
	for (int i{1}; i < 6; ++i) {
		if (i % 2 != 0) {	
			arr[i][0] = "│", arr[i][6] = "│";
			for (int j{1}; j < 6; ++j)
				{ if (j % 2 != 0) arr[i][j] = " "; else arr[i][j] = "│"; }
		} else {
			arr[i][0] = "├", arr[i][6] = "┤";
			for (int j{1}; j < 6; ++j)
				{ if (j % 2 != 0) arr[i][j] = "─"; else arr[i][j] = "┼"; }
		}
	}
	arr[6][0] = "╰", arr[6][6] = "╯";
	for (int i{1}; i < 6; ++i)
		i % 2 != 0 ? arr[6][i] = "─" : arr[6][i] = "┴";
	
	for (int i{0}; i < 7; ++i) {
		for (int j{0}; j < 7; ++j)
			if (j % 2 != 0)
				if (i % 2 == 0)
					fmt::print("{:─^3}", arr[i][j]);
				else
					fmt::print("{: ^3}", arr[i][j]);
			else fmt::print("{}", arr[i][j]);
		fmt::print("\n");
	}
*/

	// if (_getch() == 'x') fmt::print("ha");

/*
	std::string boem[3];
	boem[0], boem[2] = "╭", boem[1] = "─";
	fmt::print("{}", fmt::join(boem, " "));
*/
}