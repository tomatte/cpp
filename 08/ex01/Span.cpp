#include "Span.hpp"

Span::Span(void) : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(Span const & rhs) : _N(rhs.getMax())
{
	this->_numbers.clear();
	this->_numbers.insert(
		this->_numbers.begin(), 
		rhs.getNumbers().begin(), 
		rhs.getNumbers().end()
	);
}

Span::~Span(void)
{
	this->_numbers.clear();
}


Span & Span::operator=(Span const & rhs)
{
	this->_numbers.clear();
	this->_numbers.insert(
		this->_numbers.begin(), 
		rhs.getNumbers().begin(), 
		rhs.getNumbers().end()
	);
	this->_N = rhs._N;
}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_N)
		throw Span::MaxLimitException();
	this->_numbers.push_back(number);
}

int		Span::shortestSpan(void) const
{

}

int		Span::longestSpan(void) const
{

}

const std::vector<int> & Span::getNumbers(void) const
{
	return this->_numbers;
}

int		Span::getStored(void) const
{

}

int		Span::getMax(void) const
{

}


const char	*Span::TooFewNumbersException::what(void) const throw()
{
	return ("reached limit of numbers");
}

const char	*Span::MaxLimitException::what(void) const throw()
{
	return ("too few numbers to execute operation");
}
#include <iostream>
std::ostream & operator<<(std::ostream & o, Span const & span)
{
	std::vector<int>::const_iterator	it;
	std::vector<int> const &			numbers = span.getNumbers();

	o << '[';
	if (numbers.size() == 0)
	{
		o << ']';
		return (o);
	}
	for (it = numbers.begin(); it != (numbers.end() - 1); it++)
	{
		o << *it << ", ";
	}
	o << *it << ']';
	return (o);
}