#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int	main(void)
{
	Span	numbers(3);

	numbers.addNumber(10);
	numbers.addNumber(1);
	numbers.addNumber(2);

	std::cout << numbers << std::endl;
	return (0);
}