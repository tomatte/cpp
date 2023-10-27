#include "BitcoinExchange.hpp"

bool	BitcoinExchange::is_valid_date(const char *str)
{
	if (str == NULL)
		return (false);

	const char	format[] = "%Y-%m-%d";
	std::tm	date;
	return (strptime(str, format, &date) != NULL);
}

bool	BitcoinExchange::is_valid_number(const char *str)
{

}


void	BitcoinExchange::extract_data(std::string filename)
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
		this->prices[key] = std::atof(value);
	}
	file.close();
}

void	BitcoinExchange::convert_values(std::string filename)
{
	std::ifstream		file(filename.c_str());
	std::string			delim(" | ");
	char				buffer[256];
	std::string			line;
	std::string			key;
	std::string			value;
	size_t				n;
	std::stringstream	ss;
	double				number;
	double				price;

	if (file.fail())
	{
		std::cerr << "Error opening '" << filename << "'" << std::endl;
		return ;
	}
	file.getline(buffer, 256);
	while (file.good() && file.eof() == false)
	{
		ss.clear();
		file.getline(buffer, 256);
		line = buffer;
		n = line.find_first_of(delim);
		if (n == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		key = line.substr(0, n);
		if (is_valid_date(key.c_str()) == false)
		{
			std::cout << "Error: invalid date => " << line << std::endl;
			continue ;
		}
		value = line.substr(line.find_first_of(delim) + delim.length());
		ss << value;
		ss >> number;
		if (ss.fail())
		{
			std::cout << "Error: invalid number => " << line << "'" << value << "'" << std::endl;
			continue ;
		}
		if (number < 0)
		{
			std::cout << "Error: not a positive number.\n";
			continue ;
		}
		try
		{
			price = this->prices.at(key);
		} catch (...)
		{
			std::cout << "didn't find key => " << key << "\n";
			continue ;
		}
		std::cout << key << " => " << value << " = " 
			<< price * number << "\n";
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(void)
{
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

void	BitcoinExchange::init_prices(std::string filename)
{
	extract_data(filename);
}
