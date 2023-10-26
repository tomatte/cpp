#include "BitcoinExchange.hpp"

bool	BitcoinExchange::is_valid_date(const char *str)
{
	if (str == NULL)
		return (false);

	const char	format[] = "%Y-%m-%d";
	std::tm	date;
	return (strptime(str, format, &date) != NULL);
}

void	BitcoinExchange::extract_data(std::string data_file)
{
	std::ifstream	file(data_file.c_str());
	char			key[256];
	char			value[256];

	if (file.fail())
	{
		std::cerr << "Error opening '" << data_file << "'" << std::endl;
		return ;
	}
	file.getline(key, 256);
	while (file.good() && file.eof() == false)
	{
		file.getline(key, 256, ',');
		file.getline(value, 256);
		this->btc_data[key] = std::atof(value);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(void)
{
	extract_data("data.csv");
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

