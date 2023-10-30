#include "RPN.hpp"

RPN::RPN(void)
{

}

RPN::RPN(RPN const & rhs)
{
	(void)rhs;
}

RPN::~RPN(void)
{

}

RPN & RPN::operator=(RPN const & rhs)
{
	(void)rhs;
	return (*this);
}

void	RPN::operation(std::string str)
{
	if (str.find_first_not_of("+-/* 01234567890") != std::string::npos)
		throw std::runtime_error("Error");
}
