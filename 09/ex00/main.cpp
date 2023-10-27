#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"


int	main(int argc, char *argv[])
{
	BitcoinExchange	exchange;

	exchange.init_prices("data.csv");
	exchange.convert_values(argv[1]);
	return (0);
}