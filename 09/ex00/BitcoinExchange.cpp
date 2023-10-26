#include "BitcoinExchange.hpp"

bool	BitcoinExchange::is_valid_date(const char *str)
{
	if (str == NULL)
		return (false);

	const char	format[] = "%Y-%m-%d";
	std::tm	date;
	return (strptime(str, format, &date) != NULL);
}

void	BitcoinExchange::extract_data(t_data & storage, std::string filename)
{
	std::ifstream	file(filename.c_str());
	char			key[256];
	char			value[256];

	if (file.fail())
	{
		std::cerr << "Error opening '" << filename << "'" << std::endl;
		return ;
	}
	file.getline(key, 256);
	while (file.good() && file.eof() == false)
	{
		file.getline(key, 256, ',');
		file.getline(value, 256);
		storage[key] = std::atof(value);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(void)
{
	extract_data(this->prices, "data.csv");

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

