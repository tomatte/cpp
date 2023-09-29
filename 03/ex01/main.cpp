#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Billy");
	ScavTrap	scav("Lully");

	std::cout << std::endl;

	scav.guardGate();
	clap.beRepaired(5);
	clap.attack("Lully");
	scav.attack("Billy");
	clap.beRepaired(10);

	std::cout << std::endl;
	return (0);
}
