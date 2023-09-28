#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	julia("Julia");
	ClapTrap	james("James");

	for (int i = 0; i < 12; i++)
	{
		julia.attack("James");
	}
	julia.beRepaired(10);
	return (0);
}
