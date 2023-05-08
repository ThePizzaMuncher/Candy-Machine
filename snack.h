#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

class snacc
{
	public:
		std::string name, pricestr;
		int option;
		double price;

		snacc(std::string snack, int number, double cost) : name(snack), option(number), price(cost) {
			if (floor(cost) == cost)
				pricestr = fmt::format("€{:.0},−", cost);
			else
				pricestr = fmt::format("€{},{:.0f}", int(cost), (cost - floor(cost)) * 100);
		}
};