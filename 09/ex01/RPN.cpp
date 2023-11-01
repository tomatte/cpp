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

int	RPN::pop(void)
{
	int	num = _stack.top();
	_stack.pop();
	return (num);
}

int		RPN::convert_to_int(std::string & str)
{
	long	n = std::atol(str.c_str());

	if (n > std::numeric_limits<int>::max()
		|| n < std::numeric_limits<int>::min())
	{
		throw std::runtime_error("Error: number overflow");
	}

	if (n >= 10)
		throw std::runtime_error("Error: number greater than 9");
	return (static_cast<int>(n));
}

void	RPN::numbers_to_stack1(std::stringstream & ss)
{
	std::string	word;

	while (1)
	{
		if (ss.eof())
			throw std::runtime_error("Error");
		ss >> word;
		if (word.find_first_of("-+/*") != npos)
			break ;
		_stack.push(convert_to_int(word));
	}
	if (word.length() != 1)
		throw std::runtime_error("Error: invalid operator");
	_op = word[0];
}

void	RPN::execute_operation(void)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	const int	b = pop();
	const int	a = pop();
	_stack.push(func(a, b, _op));
}

void	RPN::operation(std::string str)
{
	verify_error(str);
	std::stringstream	ss(str);

	while (!ss.eof())
	{
		numbers_to_stack1(ss);
		execute_operation();
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << "Result: " << _stack.top() << std::endl;
}
