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

}

int		Span::shortestSpan(void) const
{

}

int		Span::longestSpan(void) const
{

}

const std::vector<int> & Span::getNumbers(void) const
{

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

const char	*Span::TooFewNumbersException::what(void) const throw()
{
	return ("too few numbers to execute operation");
}
