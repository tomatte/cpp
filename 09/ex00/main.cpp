#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"


int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}

	BitcoinExchange	exchange;
	exchange.init_prices("data.csv");
	try { exchange.convert_values(argv[1]); }
	catch(...)
	{
		//print message
		return (2);
	}
	return (0);
}