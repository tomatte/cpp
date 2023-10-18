#include <iostream>
#include "iter.hpp"

int	main(void)
{
	char	str[] = {"abcdefghijk"}; //size 11

	iter(str, 11, print_content<char>);
	std::cout << std::endl << std::endl;

	int 	numbers[] = {1, 2, 3, 4, 5};
	size_t	len = 5;
	iter(numbers, len, print_times2<int>);
	return (0);
}
