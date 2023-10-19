#include <iostream>
#include "Array.hpp"
# define NONE "\033[0m"			/* None */
# define YELLOW  "\033[33m"		/* Yellow */
# define BLUE_B "\033[0;34;1m"	/* Blue Bold */



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

void	test_copies1(void)
{
	Array<std::string>	words(3);

	words[0] = "love";
	words[1] = "wisdom";
	words[2] = "life";

	std::cout << "\n----------- test copy constructor -----------" << std::endl;
	std::cout << "words:    " << BLUE_B << words << NONE << std::endl;
	Array<std::string>	copy_one(words);
	std::cout << "copy_one: " << YELLOW << copy_one << NONE << std::endl;
	copy_one[1] = "exceptions";
	copy_one[2] = "casts";
	copy_one[0] = "templates";
	std::cout << "\nafter copy_one modification: " << std::endl;
	std::cout << "words:    " << BLUE_B << words << NONE << std::endl;
	std::cout << "copy_one: " << YELLOW << copy_one << NONE << std::endl;
}

void	test_copies2(void)
{
	Array<std::string>	words(3);

	words[0] = "earth";
	words[1] = "moon";
	words[2] = "sun";

	std::cout << "\n----------- test copy asignment operator -----------" << std::endl;
	std::cout << "words:    " << BLUE_B << words << NONE << std::endl;
	Array<std::string>	copy_two;
	copy_two = words;
	std::cout << "copy_two: " << YELLOW << copy_two << NONE << std::endl;
	copy_two[0] = "blue";
	copy_two[1] = "silver";
	copy_two[2] = "yellow";
	std::cout << "\nafter copy_two modification: " << std::endl;
	std::cout << "words:    " << BLUE_B << words << NONE << std::endl;
	std::cout << "copy_two: " << YELLOW << copy_two << NONE << std::endl;
}

int	main(void)
{


	test_integers();
	test_floaters();
	test_stringers();
	test_copies1();
	test_copies2();

	return (0);
}
