#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include "ColorOut.hpp"

int	main(void)
{
	std::vector<int>	numbers;
	numbers.push_back(19);
	numbers.push_back(15);
	numbers.push_back(10);

	std::list<int>	names;
	names.push_back(03);
	names.push_back(01);
	names.push_back(06);

	const int	value1 = 10;
	if (easyfind(numbers, value1) == numbers.end())
		ColorOut::red << "Value " << value1 << " not found." << std::endl;
	else
		ColorOut::green << "Value " << value1 << " was found!!!" << std::endl;
		
	easyfind(names, 02);
	return (0);
}