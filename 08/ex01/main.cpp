#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int	main(void)
{
	Span	numbers(4);

	numbers.addNumber(10);
	numbers.addNumber(1);
	numbers.addNumber(5);
	numbers.addNumber(20);

	std::cout << numbers << std::endl;
	std::cout << "Shortest span: " << numbers.shortestSpan() << std::endl;
	std::cout << "Longest span: " << numbers.longestSpan() << std::endl;
	return (0);
}