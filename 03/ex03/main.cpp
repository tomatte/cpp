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
	DiamondTrap	diamond("Hulk");
	DiamondTrap	copy;
	ScavTrap	aux("Max");
	copy = diamond;
	std::cout << std::endl;

	copy.attack("Max");
	copy.whoAmI();


	std::cout << std::endl;
	return (0);
}
