#include "ScalarConverter.hpp"
#include <iostream>

char	ScalarConverter::n_char;
int		ScalarConverter::n_int;
float	ScalarConverter::n_float;
double	ScalarConverter::n_double;

bool		(*ScalarConverter::convertions[4])(std::string) = {
		ScalarConverter::convert_to_char,
		ScalarConverter::convert_to_double,
		ScalarConverter::convert_to_float,
		ScalarConverter::convert_to_int
	};

bool		ScalarConverter::convert_to_char(std::string literal)
{
	std::cout << "char converting\n";
	return (false);
}

bool		ScalarConverter::convert_to_int(std::string literal)
{
	return (false);
}

bool		ScalarConverter::convert_to_float(std::string literal)
{
	return (false);
}

bool		ScalarConverter::convert_to_double(std::string literal)
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
