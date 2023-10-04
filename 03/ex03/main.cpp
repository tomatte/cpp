#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <cstdlib>

void	fight(ScavTrap & s, FragTrap & f)
{
	std::cout << "\n----- Fight started!!! -----\n";
	while (1)
	{
		if (s.is_dead() || f.is_dead())
			return ;
		s.attack(f.get_name());
		f.attack(s.get_name());
	}
}

int	main(void)
{
	std::cout << "Constructing diamond ClapTrap: \n";
	DiamondTrap	diamond("Hulk");
	std::cout << "\n";

	std::cout << "Constructing diamond_copy ClapTrap: \n";
	DiamondTrap	diamond_copy(diamond);
	std::cout << "\n";

	ClapTrap	clap("Max");

	std::cout << std::endl;

	diamond.attack("Max");
	diamond.attack("Hulk");
	diamond.guardGate();
	diamond.beRepaired(50);
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond_copy.whoAmI();

	std::cout << std::endl;
	return (0);
}
