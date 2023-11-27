#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

void			BitcoinExchange::deep_copy(const t_data & src, t_data & dst)
{
	t_data::const_iterator	it;

	dst.clear();
	for (it = src.begin(); it != src.end(); it++)
		dst[(*it).first] = (*it).second;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs)
{
	deep_copy(rhs.get_database(), this->_database);
}


BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	deep_copy(rhs.get_database(), this->_database);
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

t_data const	BitcoinExchange::get_database(void) const
{
	return (this->_database);
}

void	BitcoinExchange::init_database(std::string filename)
{
	extract_data(filename);
}

bool	BitcoinExchange::is_valid_date(const char *str)
{
	if (str == NULL)
		return (false);

	const char	format[] = "%Y-%m-%d";
	std::tm	date;
	return (strptime(str, format, &date) != NULL);
}

void	BitcoinExchange::extract_data(std::string filename)
{
	std::ifstream	file(filename.c_str());
	char			key[256];
	char			value[256];

	if (file.fail())
		throw std::runtime_error("Error opening '" + filename + "'");
	file.getline(key, 256);
	while (file.good() && file.eof() == false)
	{
		file.getline(key, 256, ',');
		file.getline(value, 256);
		this->_database[key] = std::atof(value);
	}
	file.close();
}

void	BitcoinExchange::print_convertion(std::string key, double value)
{
	t_data::iterator it = this->_database.lower_bound(key);
	if (it != this->_database.begin() && (*it).first != key)
		it--;
	std::cout << key << " => " << value << " = " 
		<< (*it).second * value << "\n";
}

double	BitcoinExchange::read_number(std::string & line, std::string & delim)
{
	std::string			value;
	std::stringstream	ss;
	double				number;
	std::string			err_msg;

	try
	{
		value = line.substr(line.find_first_of(delim) + delim.length());
	}
	catch (std::exception & e)
	{
		(void) e;
		throw std::runtime_error("Error: bad input");
	}
	ss << value;
	ss >> number;
	if (ss.fail())
		throw std::runtime_error("Error: invalid number => " + line);
	if (number < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (number > 1000)
		throw std::runtime_error("Error: too large a number.");
	return (number);
}

std::string	BitcoinExchange::read_date(std::string & line, std::string & delim)
{
	size_t				n;
	std::string			date;

	n = line.find_first_of(delim);
	if (n == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);
	date = line.substr(0, n);
	if (is_valid_date(date.c_str()) == false)
		throw std::runtime_error("Error: invalid date => " + line);
	return (date);
}

void	BitcoinExchange::convert_values(std::string filename)
{
	std::ifstream		file(filename.c_str());
	std::string			delim(" | ");
	char				buffer[256];
	std::string			line;
	std::string			date;
	double				number;

	if (file.fail())
		throw std::runtime_error("Error opening '" + filename + "'");
	file.getline(buffer, 256);
	while (file.good() && file.eof() == false)
	{
		file.getline(buffer, 256);
		line = buffer;
		try 
		{
			date = read_date(line, delim);
			number = read_number(line, delim);
			print_convertion(date, number);
		}
		catch (std::runtime_error & e)
		{
			std::cout << e.what() << "\n";
		}
	}
	file.close();
}
