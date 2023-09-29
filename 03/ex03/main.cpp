#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
	ClapTrap	clap("Billy");
	ScavTrap	scav("Lully");
	FragTrap	frag("Blade");

	std::cout << std::endl;

	frag.highFivesGuys();
	clap.beRepaired(100);
	scav.guardGate();
	fight(scav, frag);
	std::cout << std::endl;

	std::cout << clap.get_name() << "'s hit points: " << clap.get_hit_points() << "\n";
	std::cout << scav.get_name() << "'s hit points: " << scav.get_hit_points() << "\n";
	std::cout << frag.get_name() << "'s hit points: " << frag.get_hit_points() << "\n";

	std::cout << std::endl;
	clap.beRepaired(999);
	frag.highFivesGuys();
	scav.guardGate();
	std::cout << std::endl;

	return (0);
}
