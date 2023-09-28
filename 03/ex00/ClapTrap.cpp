#include "ClapTrap.hpp"
#include <iostream>

int	ClapTrap::total = 0;

ClapTrap	*ClapTrap::clap_traps[];

void	ClapTrap::store_clap_trap(ClapTrap *clap_trap)
{
	ClapTrap::total++;
	ClapTrap::clap_traps[ClapTrap::total - 1] = clap_trap;
}

ClapTrap	*ClapTrap::find_clap_trap(std::string const & name)
{
	for (int i = 0; i < ClapTrap::total; i++) {
		if (ClapTrap::clap_traps[i]->name == name)
			return ClapTrap::clap_traps[i];
	}
	return NULL;
}

ClapTrap::ClapTrap(void) : name(""), hit_points(10), 
energy_points(10), attack_damage(0)
{
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), 
energy_points(10), attack_damage(0)
{
	store_clap_trap(this);
}

ClapTrap::~ClapTrap(void)
{
}

void	ClapTrap::attack(std::string const & target)
{
	ClapTrap	*clap_target;

	clap_target = find_clap_trap(target);
	if (clap_target == NULL)
	{
		std::cout << "Target " << target << "not found.\n";
		return ;
	}
	clap_target->hit_points -= this->attack_damage;
	std::cout << "ClapTrap " << this->name << " attacks " << clap_target->name \
		<< ", causing " << this->attack_damage << " points of damage!\n";
}
