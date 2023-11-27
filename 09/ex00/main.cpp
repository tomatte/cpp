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
	try
	{
		exchange.init_database("data.csv");
		exchange.convert_values(argv[1]);
	}
	catch(std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
		return (2);
	}

	std::cout << std::endl;
	BitcoinExchange	copy(exchange);
	std::cout << "--- Copy ---" << std::endl; 
	try
	{
		copy.convert_values(argv[1]);
	}
	catch (std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}