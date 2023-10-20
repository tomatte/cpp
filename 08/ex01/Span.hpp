#ifndef SPAN_H
# define SPAN_H
# include <stdexcept>
# include <vector>
# include <ostream>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_numbers;

	static int	abs(int n);

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
	int		getMax(void) const;
};

std::ostream & operator<<(std::ostream & o, Span const & span);

#endif