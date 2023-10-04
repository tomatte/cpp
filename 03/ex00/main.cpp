#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	julia("Julia");
	ClapTrap	james("James");

	std::cout << std::endl;
	julia.attack("James");
	julia.beRepaired(10);

	std::cout << std::endl;
	james.attack("Emanuel");
	james.beRepaired(0);
	james.takeDamage(10);
	james.beRepaired(999);
	return (0);
}
