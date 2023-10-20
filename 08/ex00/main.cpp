#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include "ColorOut.hpp"

int	main(void)
{

	ColorOut::blue << "-------- Using vector --------" << std::endl;
	std::vector<int>	numbers;
	numbers.push_back(19);
	numbers.push_back(15);
	numbers.push_back(10);

	const int	value1 = 10;
	if (easyfind(numbers, value1) == numbers.end())
		ColorOut::red << "Value " << value1 << " not found." << std::endl;
	else
		ColorOut::green << "Value " << value1 << " was found!!!" << std::endl;
	
	ColorOut::blue << std::endl << "-------- Using list --------" << std::endl;
	std::list<int>	soldiers;
	soldiers.push_back(03);
	soldiers.push_back(01);
	soldiers.push_back(06);

	const int	value2 = 02;
	if (easyfind(soldiers, value2) == soldiers.end())
		ColorOut::red << "Value " << value2 << " not found." << std::endl;
	else
		ColorOut::green << "Value " << value2 << " was found!!!" << std::endl;
	return (0);
}