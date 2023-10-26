#include "BitcoinExchange.hpp"

void	BitcoinExchange::extract_data(std::string data_file)
{
	std::ifstream	file;
	char			key[256];
	char			value[256];

	file.open(data_file.c_str());
	file.getline(key, 256);
	while (file.good() && file.eof() == false)
	{
		file.getline(key, 256, ',');
		file.getline(value, 256);
		this->btc_data[key] = std::atof(value);
	}
	file.close();
	std::cout << "first: " << this->btc_data.at("2017-09-27") << std::endl;
}

BitcoinExchange::BitcoinExchange(void)
{
	BitcoinExchange::extract_data("data.csv");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs)
{

}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{

}

