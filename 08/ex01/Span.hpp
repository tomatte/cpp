#ifndef SPAN_H
# define SPAN_H
# include <stdexcept>
# include <vector>
# include <ostream>

typedef std::vector<int>::iterator ft_iterator;

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_numbers;

	int		shortest_a;
	int		shortest_b;
	int		longest_a;
	int		longest_b;

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
	void	addNumbersBulk(ft_iterator begin, ft_iterator end);
	int		shortestSpan(void);
	int		longestSpan(void);
	int		getMax(void) const;
	void	results(void);
	
};

std::ostream & operator<<(std::ostream & o, Span const & span);

#endif