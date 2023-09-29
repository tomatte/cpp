#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav("Lully");
	ClapTrap	clap("Billy");

	clap.attack("Lully");
	scav.attack("Billy");
	clap.beRepaired(10);
	return (0);
}
