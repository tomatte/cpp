#include "Span.hpp"
#include <algorithm>
#include <limits>

int	Span::abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

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
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_N)
		throw Span::MaxLimitException();
	this->_numbers.push_back(number);
}

int		Span::shortestSpan(void) const
{
	std::vector<int>::const_iterator	i;
	std::vector<int>::const_iterator	j;
	int									shortest;
	
	shortest = std::numeric_limits<int>::max();
	if (this->_numbers.size() <= 1)
		throw Span::TooFewNumbersException();
	for (i = this->_numbers.begin(); i != (this->_numbers.end() - 1); i++)
	{
		for (j = i + 1; j != this->_numbers.end(); j++)
		{
			if (Span::abs(*i - *j) < shortest)
				shortest = Span::abs(*i - *j);
		}
	}
	return (shortest);
}

int		Span::longestSpan(void) const
{
	std::vector<int>::const_iterator	i;
	std::vector<int>::const_iterator	j;
	int									shortest;
	
	shortest = 0;
	if (this->_numbers.size() <= 1)
		throw Span::TooFewNumbersException();
	for (i = this->_numbers.begin(); i != (this->_numbers.end() - 1); i++)
	{
		for (j = i + 1; j != this->_numbers.end(); j++)
		{
			if (Span::abs(*i - *j) > shortest)
				shortest = Span::abs(*i - *j);
		}
	}
	return (shortest);
}

const std::vector<int> & Span::getNumbers(void) const
{
	return (this->_numbers);
}

int		Span::getMax(void) const
{
	return (this->_N);
}


const char	*Span::TooFewNumbersException::what(void) const throw()
{
	return ("reached limit of numbers");
}

const char	*Span::MaxLimitException::what(void) const throw()
{
	return ("too few numbers to execute operation");
}

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