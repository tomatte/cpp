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
	if (str.find_first_not_of("+-/* 01234567890") != npos)
		throw std::runtime_error("Error");
}


int	RPN::func(int a, int b, char op)
{
	switch (op)
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

/*
	op = find first operator
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

char	RPN::find_operator(std::string & str)
{
	if (str.find_first_of(OPERANDS) == npos)
		throw std::runtime_error("Error");
	return str.at(str.find_first_of(OPERANDS));
}

int	RPN::get_operand(std::string & str)
{
	long	n = std::atol(str.c_str());
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw std::runtime_error("Error: integer overflow");
	if (n >= 10)
		throw std::runtime_error("Error: number greater than 9");
	str = str.substr(str.find_first_not_of(' '));
	if (n == 0 && str[0] != '0')
		throw std::runtime_error("Error: invalid number");
	str = str.substr(str.find_first_of(' '));
	str = str.substr(str.find_first_not_of(' '));
	return (static_cast<int>(n));
}

void	RPN::operation(std::string str)
{
	verify_error(str);

	char	op = find_operator(str);
	int		operand = get_operand(str);
	std::cout << "Operator: " << op << "\nOperand: " << operand << std::endl;
}
