#include "ScalarConverter.hpp"
#include <iostream>

char	ScalarConverter::n_char;
int		ScalarConverter::n_int;
float	ScalarConverter::n_float;
double	ScalarConverter::n_double;

void	ScalarConverter::print_everything(void)
{
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Char: ";
	if (ScalarConverter::n_char < 32 || ScalarConverter::n_char == 127)
		std::cout << "non-printable char" << std::endl;
	else
		std::cout << ScalarConverter::n_char << std::endl;
	std::cout << "Int: " << ScalarConverter::n_int << std::endl;
	std::cout << "Float: " << ScalarConverter::n_float << std::endl;
	std::cout << "Double: " << ScalarConverter::n_double << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}


bool	(*ScalarConverter::convertions[4])(std::string) = {
		ScalarConverter::convert_to_double,
		ScalarConverter::convert_to_float,
		ScalarConverter::convert_to_int,
		ScalarConverter::convert_to_char
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
	return (false);
}

bool	ScalarConverter::convert_to_float(std::string literal)
{
	return (false);
}

bool	ScalarConverter::convert_to_double(std::string literal)
{
	return (false);
}

void	ScalarConverter::convert(std::string literal)
{
	for (int i = 0; i < 4; i++)
	{
		if (ScalarConverter::convertions[i](literal))
			return ;
	}
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
