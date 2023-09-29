#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Billy");
	FragTrap	frag("Lully");

	std::cout << std::endl;

	frag.highFivesGuys();
	clap.beRepaired(5);
	clap.attack("Lully");
	frag.attack("Billy");
	clap.beRepaired(10);

	frag.highFivesGuys();
	frag.highFivesGuys();

	std::cout << std::endl;
	return (0);
}
