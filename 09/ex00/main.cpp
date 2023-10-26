#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"


int	main(int argc, char *argv[])
{
	BitcoinExchange	exchange;

	if (BitcoinExchange::is_valid_date("2023-12-10"))
		std::cout << "VALID!\n";
	else
		std::cout << "INVALID :(\n";

	return (0);
}