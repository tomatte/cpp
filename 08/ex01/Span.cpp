#include "Span.hpp"

Span::Span(void) : _N(0), _numbers(NULL), _stored(0)
{
}

Span::Span(unsigned int N) : _N(N), _numbers(NULL), _stored(0)
{
}

Span::Span(Span const & rhs) : _N(), _numbers(NULL), _stored(0)
{

}

Span::~Span(void)
{

}


Span & Span::operator=(Span const & rhs)
{

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

int		Span::getNumber(int index) const
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
