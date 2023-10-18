#include <iostream>
#include "Array.hpp"
#define BLUE_B "\033[0;34;1m"		/* Blue Bold */
#define NONE "\033[0m"			/* None */


void	test_integers(void)
{
	Array<int>		integers;
	int				bunch_of_ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << "----------- test_integers -----------" << std::endl;
	std::cout << "Just instanciated:     " << BLUE_B << integers << NONE << std::endl;
	integers.set_array(bunch_of_ints, 10);
	std::cout << "After using set_array: " << BLUE_B << integers << NONE << std::endl;
	std::cout << std::endl;
}

void	test_floaters(void)
{
	Array<double>	floaters(5);
	double			bunch_of_doubles[] = {30.6555, 218937.9999, 0.123, 123.456, 41.99};

	std::cout << "----------- test_floaters -----------" << std::endl;
	std::cout << "Just instanciated:  " << BLUE_B << floaters << NONE << std::endl;
	for (unsigned int i = 0; i < floaters.size(); i++)
		floaters[i] = bunch_of_doubles[i];
	std::cout << "After asign values: " << BLUE_B << floaters << NONE << std::endl;
	std::cout << std::endl;
}

void	test_stringers(void)
{
	Array<std::string>	stringers(3);

	std::cout << "----------- test_stringers -----------" << std::endl;
	std::cout << "Just instanciated:  " << BLUE_B << stringers << NONE << std::endl;
	stringers[0] = "orange";
	stringers[1] = "lemon";
	stringers[2] = "apple";
	std::cout << "After asign values: " << BLUE_B << stringers << NONE << std::endl;
}

int	main(void)
{


	test_integers();
	test_floaters();
	test_stringers();

	return (0);
}
