#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

char	ScalarConverter::n_char;
int		ScalarConverter::n_int;
float	ScalarConverter::n_float;
double	ScalarConverter::n_double;

bool		ScalarConverter::is_number_ok(std::string & literal)
{
	if (literal.length() == 0)
		return (false);
	if (literal.length() == 1)
		return (true);
	if (literal.find('.') != std::string::npos && 
		literal.substr(literal.find('.') + 1).find('.') != std::string::npos)
	{
		return (false);
	}
	if (literal[literal.length() - 1] == '.')
		return (false);
	if (literal[0] == '.')
		return (false);
	if (literal.substr(1).find_first_of("-+") != std::string::npos)
		return (false);
	return (true);
}

void		ScalarConverter::trim_zeros(std::string & literal)
{
	int	i = 0;

	if (literal.length() <= 1)
		return ;
	while (literal[i] == '0')
		i++;
	if (literal[i] != '.' || !literal[i])
		return ;
	if (!literal[i + 1])
		return ;
	while (literal[++i] == '0');
	if (literal[i] && literal[i] != 'f')
		return ;
	if (!literal[i])
	{
		literal = "0.0";
		return ;
	}
	if (literal.substr(literal.find('f')).length() > 1)
		return ;
	else
		literal = "0.0f";
}

void		ScalarConverter::print_char(void)
{
	int	num;

	num = static_cast<int>(ScalarConverter::n_double);
	std::cout << "char: ";
	if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		std::cout << "impossible";
	else if (ScalarConverter::n_char < 32 || ScalarConverter::n_char == 127)
		std::cout << "Non displayable";
	else
		std::cout << '\'' << ScalarConverter::n_char << '\'';
	std::cout << std::endl;
}

void		ScalarConverter::print_double(void)
{
	std::cout << "double: " << ScalarConverter::n_double;
	if (ScalarConverter::n_double == static_cast<int>(ScalarConverter::n_double))
		std::cout << ".0";
	std::cout << std::endl;
}

void		ScalarConverter::print_float(void)
{
	std::cout << "float: " << ScalarConverter::n_float;
	if (ScalarConverter::n_float != static_cast<int>(ScalarConverter::n_float))
		std::cout << "f";
	else
		std::cout << ".0f";
	std::cout << std::endl;
}

void		ScalarConverter::print_int(void)
{
	long int	num;

	num = static_cast<long int>(ScalarConverter::n_double);
	std::cout << "int: ";
	if (num > ScalarConverter::n_int || num < ScalarConverter::n_int)
		std::cout << "impossible";
	else
		std::cout << ScalarConverter::n_int;
	std::cout << std::endl;
}

void	ScalarConverter::print_everything(void)
{
	ScalarConverter::print_char();
	ScalarConverter::print_int();
	ScalarConverter::print_float();
	ScalarConverter::print_double();
}

bool	(*ScalarConverter::convertions[OPERATIONS])(std::string) = {
		ScalarConverter::convert_to_double,
		ScalarConverter::convert_to_float,
		ScalarConverter::convert_to_int,
		ScalarConverter::convert_to_char,
		ScalarConverter::convert_double_specials,
		ScalarConverter::convert_float_specials
	};

bool	ScalarConverter::convert_to_char(std::string literal)
{
	if (literal.length() != 1)
		return (false);
	ScalarConverter::n_char = literal.at(0);
	ScalarConverter::n_double = static_cast<double>(literal.at(0));
	ScalarConverter::n_float = static_cast<float>(literal.at(0));
	ScalarConverter::n_int = static_cast<int>(literal.at(0));
	ScalarConverter::print_everything();
	return (true);
}

bool	ScalarConverter::convert_to_int(std::string literal)
{
	long int	num;

	if (literal.find_first_not_of("-0123456789") != std::string::npos)
		return (false);
	if (literal[0] == '-' && literal.length() == 1)
		return (false);
	num = std::atol(literal.c_str());
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return (false);
	ScalarConverter::n_int = static_cast<int>(num);
	ScalarConverter::n_char = static_cast<char>(ScalarConverter::n_int);
	ScalarConverter::n_double = static_cast<double>(ScalarConverter::n_int);
	ScalarConverter::n_float = static_cast<float>(ScalarConverter::n_int);
	ScalarConverter::print_everything();
	return (true);
}

bool	ScalarConverter::convert_to_float(std::string literal)
{
	std::string	aux;

	if (literal.find('f') == std::string::npos)
		return (false);
	if (literal.substr(literal.find('f')).length() != 1)
		return (false);
	if (literal.find('.') == std::string::npos)
		return (false);
	aux = literal.substr(0, literal.length() - 1);
	ScalarConverter::n_float = static_cast<float>(std::atof(aux.c_str()));
	if (ScalarConverter::n_float == 0 && literal != "0.0f")
		return (false);
	ScalarConverter::n_char = static_cast<char>(ScalarConverter::n_float);
	ScalarConverter::n_int = static_cast<int>(ScalarConverter::n_float);
	ScalarConverter::n_double = static_cast<double>(ScalarConverter::n_float);
	ScalarConverter::print_everything();
	return (true);
}

bool	ScalarConverter::convert_to_double(std::string literal)
{
	if (literal.find('f') != std::string::npos)
		return (false);
	if (literal.find('.') == std::string::npos)
		return (false);
	ScalarConverter::n_double = std::atof(literal.c_str());
	if (ScalarConverter::n_double == 0 && literal != "0.0")
		return (false);
	ScalarConverter::n_char = static_cast<char>(ScalarConverter::n_double);
	ScalarConverter::n_int = static_cast<int>(ScalarConverter::n_double);
	ScalarConverter::n_float = static_cast<float>(ScalarConverter::n_double);
	ScalarConverter::print_everything();
	return (true);
}

bool		ScalarConverter::convert_double_specials(std::string literal)
{
	if (literal != "nan" && literal != "+inf" && literal != "-inf")
		return (false);
	if (literal == "nan")
		ScalarConverter::n_double = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "-inf")
		ScalarConverter::n_double = -std::numeric_limits<double>::infinity();
	else
		ScalarConverter::n_double = std::numeric_limits<double>::infinity();
	ScalarConverter::n_char = static_cast<char>(ScalarConverter::n_double);
	ScalarConverter::n_int = static_cast<int>(ScalarConverter::n_double);
	ScalarConverter::n_float = static_cast<float>(ScalarConverter::n_double);
	ScalarConverter::print_everything();
	return (true);
}

bool		ScalarConverter::convert_float_specials(std::string literal)
{
	if (literal != "nanf" && literal != "inff" && literal != "+inff" && literal != "-inff")
		return (false);
	if (literal == "nanf")
		ScalarConverter::n_float = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "-inff")
		ScalarConverter::n_float = -std::numeric_limits<float>::infinity();
	else
		ScalarConverter::n_float = std::numeric_limits<float>::infinity();
	ScalarConverter::n_char = static_cast<char>(ScalarConverter::n_float);
	ScalarConverter::n_int = static_cast<int>(ScalarConverter::n_float);
	ScalarConverter::n_double = static_cast<double>(ScalarConverter::n_float);
	ScalarConverter::print_everything();
	return (true);
}

void	ScalarConverter::convert(std::string literal)
{
	if (ScalarConverter::is_number_ok(literal) == false)
	{
		std::cout << "Type conversion is not possible." << std::endl;
		return ;
	}
	ScalarConverter::trim_zeros(literal);
	for (int i = 0; i < OPERATIONS; i++)
	{
		if (ScalarConverter::convertions[i](literal))
			return ;
	}
	std::cout << "Type conversion is not possible." << std::endl;
}

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & rhs)
{
	(void) rhs;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void) rhs;
	return (*this);
}
