#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Billy");
	FragTrap	scav("Lully");

	std::cout << std::endl;

	scav.guardGate();
	clap.beRepaired(5);
	clap.attack("Lully");
	scav.attack("Billy");
	clap.beRepaired(10);

	std::cout << std::endl;
	return (0);
}
