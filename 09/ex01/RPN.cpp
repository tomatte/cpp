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

char	RPN::find_operator(std::string const & str)
{
	if (str.find_first_of(OPERANDS) == npos)
		throw std::runtime_error("Error");
	return str.at(str.find_first_of(OPERANDS));
}

int	RPN::pop(ft_stack & s)
{
	int	num = s.top();
	s.pop();
	return (num);
}

/* 


place numbers on stack1 until find operator
save operator in a char
save size of stack1
place numbers from stack1 into stack2 to be in right order
execute operation in size numbers of stack2
when just an operator is found then aply it to all numbers in stack2 until only 1 is remaining


	NEEDED:
		2 stacks
		1 operator: char
		1 len: int
 */

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
			throw std::runtime_error("Error: eof");
		ss >> word;
		if (word.find_first_of("-+/*") != npos)
			break ;
		this->_stack1.push(convert_to_int(word));
	}
	this->op = word[0];
	this->len = this->_stack1.size();
}

void	RPN::from_stack1_to_stack2(void)
{
	while (this->_stack1.empty() == false)
		this->_stack2.push(pop(this->_stack1));
}

void	RPN::execute_operation(void)
{
	if (this->len == 0)
		this->len = this->_stack2.size();

	int result;
	while (this->len > 1)
	{
		result = func(pop(this->_stack2), pop(this->_stack2), this->op);
		this->_stack2.push(result);
		this->len--;
	}
}

void	RPN::operation(std::string str)
{
	verify_error(str);
	std::stringstream	ss(str);

	while (!ss.eof())
	{
		numbers_to_stack1(ss);
		from_stack1_to_stack2();
		execute_operation();
		std::cout << "Result: " << this->_stack2.top() << "  Size:" << this->_stack2.size() << std::endl;
	}
	std::cout << "Result: " << this->_stack2.top() << std::endl;
}

/* 
	while (this->_stack1.empty() == false)
	{
		std::cout << "stack1: " << this->_stack1.top() << "   size: " << this->_stack1.size() << "\n";
		this->_stack1.pop();
	}

	while (this->_stack2.empty() == false)
	{
		std::cout << "stack2: " << this->_stack2.top() << "   size: " << this->_stack2.size() << "\n";
		this->_stack2.pop();
	}
	std::cout << "op: " << this->op << "  len: " << this->len << "\n";
 */