#ifndef SPAN_H
# define SPAN_H
# include <stdexcept>

class Span
{
private:
	unsigned int	_N;
	int				*_numbers;
	int				_stored;

	class MaxLimitException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};

	class TooFewNumbersException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};

public:
	Span(void);
	Span(unsigned int N);
	Span(Span const & rhs);
	~Span(void);

	Span & operator=(Span const & rhs);

	void	addNumber(int number);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
	int		getNumber(int index) const;
	int		getStored(void) const;
	int		getMax(void) const;
};

#endif