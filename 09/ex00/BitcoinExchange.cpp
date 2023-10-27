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

void	BitcoinExchange::print_convertion(std::string key, double value)
{
	t_data::iterator it = this->prices.lower_bound(key);
	if (it != this->prices.begin() && (*it).first != key)
		it--;
	std::cout << key << " => " << value << " = " 
		<< (*it).second * value << "\n";
}

double	BitcoinExchange::read_number(std::string & line, std::string & delim)
{
	std::string			value;
	std::stringstream	ss;
	double				number;
	
	value = line.substr(line.find_first_of(delim) + delim.length());
	ss << value;
	ss >> number;
	if (ss.fail())
	{
		std::cout << "Error: invalid number => " << line << "'" << value << "'" << std::endl;
		throw std::exception();
	}
	if (number < 0)
	{
		std::cout << "Error: not a positive number.\n";
		throw std::exception();
	}
	if (number > std::numeric_limits<int>::max())
	{
		std::cout << "Error: too large a number.\n";
		throw std::exception();
	}
	return (number);
}


void	BitcoinExchange::convert_values(std::string filename)
{
	std::ifstream		file(filename.c_str());
	std::string			delim(" | ");
	char				buffer[256];
	std::string			line;
	std::string			key;
	size_t				n;
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
		try { number = read_number(line, delim); }
		catch (...)
		{
			//print error message
			continue ;
		}
		print_convertion(key, number);
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
