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

void	RPN::verify_error(std::string & str) const
{
	if (str.find_first_not_of("+-/* 01234567890") != std::string::npos)
		throw std::runtime_error("Error");
}

/*
	find first operator
	operand = get_operand(str);
	if (operand)
		push operand
	else
		while (stack.size() >= 2)
		{
			operand = stack_top()
			push(operand + stack_top())
		}
	while (not operator)
		result = operate(stack_top, get_operand)
		push(result)
	if (str.empty() && stack.size() == 1)
		return stack_top()
 */

int	RPN::func(int a, int b, char operand)
{
	switch (operand)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '/':
			return (a / b);
		case '*':
			return (a * b);
		default:
			return (0);
	}
}

void	RPN::operation(std::string str)
{
	verify_error(str);


}
