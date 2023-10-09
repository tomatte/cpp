#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int	main(void)
{
	AMateria	*ice = new Ice();

	delete ice;
	std::cout << "Hello from main!\n";
	return (0);
}
