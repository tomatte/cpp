#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

char	ScalarConverter::n_char;
int		ScalarConverter::n_int;
float	ScalarConverter::n_float;
double	ScalarConverter::n_double;

void		ScalarConverter::trim_zeros(std::string & literal)
{
	int	i = 0;

	if (literal[i] == '.')
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
		literal = "0.0";
	if (literal.substr(literal.find('f')).length() > 1)
		return ;
	else
		literal = "0.0f";
}

void	ScalarConverter::print_everything(void)
{
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "char: ";
	if (ScalarConverter::n_char < 32 || ScalarConverter::n_char == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' << ScalarConverter::n_char << '\'' << std::endl;
	std::cout << "int: " << ScalarConverter::n_int << std::endl;
	std::cout << "float: " << ScalarConverter::n_float;
	if (ScalarConverter::n_float != static_cast<int>(ScalarConverter::n_float))
		std::cout << "f" << std::endl;
	else
		std::cout << ".0f" << std::endl;
	std::cout << "double: " << ScalarConverter::n_double;
	if (ScalarConverter::n_double == static_cast<int>(ScalarConverter::n_double))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
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
	if (literal.find_first_not_of("-0123456789") != std::string::npos)
		return (false);
	if (literal[0] == '-' && literal.length() == 1)
		return (false);
	ScalarConverter::n_int = std::atoi(literal.c_str());
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
	ScalarConverter::n_float = static_cast<float>(ScalarConverter::n_double);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << ScalarConverter::n_float << 'f' << std::endl;
	std::cout << "double: " << ScalarConverter::n_double << std::endl;
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
	ScalarConverter::n_double = static_cast<float>(ScalarConverter::n_float);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << ScalarConverter::n_float << 'f' << std::endl;
	std::cout << "double: " << ScalarConverter::n_double << std::endl;
	return (true);
}

void	ScalarConverter::convert(std::string literal)
{
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
