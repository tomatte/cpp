#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <iostream>
#define COLOROUT_H
#define NONE "\033[0m"			/* None */
#define RED "\033[0;31m"		/* Red */
#define GREEN "\033[0;32m"		/* Green */
#define GREEN_B "\033[0;32;1m"	/* Green Bold */
#define YELLOW  "\033[33m"		/* Yellow */
#define BLUE "\033[0;34m"		/* Blue */
#define BLUE_B "\033[0;34;1m"	/* Blue Bold */
#define MAGENTA "\033[35m"		/* Magenta */
#define CYAN    "\033[36m"		/* Cyan */
#define WHITE   "\033[37m"		/* White */

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
	this->_numbers.reserve(N);
}

Span::Span(Span const & rhs) : _N(rhs.getMax())
{
	this->_numbers.clear();
	this->_numbers.reserve(this->_N);
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
	this->_N = rhs.getMax();
	this->_numbers.reserve(rhs.getMax());
	this->_numbers.insert(
		this->_numbers.begin(), 
		rhs.getNumbers().begin(), 
		rhs.getNumbers().end()
	);
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_N)
		throw Span::MaxLimitException();
	this->_numbers.push_back(number);
}

void	Span::addNumbersBulk(ft_iterator begin, ft_iterator end)
{
	for (ft_iterator i = begin; i != end; i++)
	{
		if (this->_numbers.size() >= this->_N)
			throw Span::MaxLimitException();
		this->_numbers.push_back(*i);
	}
}

int		Span::shortestSpan(void)
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
			if (std::abs(*i - *j) < shortest)
			{
				shortest = std::abs(*i - *j);
				this->shortest_a = *i;
				this->shortest_b = *j;
			}
		}
	}
	return (shortest);
}

int		Span::longestSpan(void)
{
	std::vector<int>::const_iterator	i;
	std::vector<int>::const_iterator	j;
	int									longest;
	
	longest = 0;
	if (this->_numbers.size() <= 1)
		throw Span::TooFewNumbersException();
	for (i = this->_numbers.begin(); i != (this->_numbers.end() - 1); i++)
	{
		for (j = i + 1; j != this->_numbers.end(); j++)
		{
			if (Span::abs(*i - *j) > longest)
			{
				longest = Span::abs(*i - *j);
				this->longest_a = *i;
				this->longest_b = *j;
			}
		}
	}
	return (longest);
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
	return ("too few numbers to execute operation");
}

const char	*Span::MaxLimitException::what(void) const throw()
{
	return ("reached limit of numbers");
}

void	Span::results(void)
{
	std::cout << "------ Numbers -------" << std::endl;
	std::cout << *this << std::endl;
	std::cout << "-------- shortest --------" << std::endl;
	const int shortest = this->shortestSpan();
	std::cout << YELLOW << "[ " << this->shortest_a << ", " << this->shortest_b 
		<< " ]:  " << shortest << NONE << std::endl;
	const int longest = this->longestSpan();
	std::cout << "-------- longest --------" << std::endl;
	std::cout << RED <<"[ " << this->longest_a << ", " 
		<< this->longest_b << " ]:  " << longest << NONE << std::endl;
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