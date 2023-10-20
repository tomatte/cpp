#ifndef SPAN_H
# define SPAN_H
# include <stdexcept>
# include <vector>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_numbers;

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

	const std::vector<int> & getNumbers(void) const;
	void	addNumber(int number);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
	int		getStored(void) const;
	int		getMax(void) const;
};

#endif