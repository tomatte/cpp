#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap string constructor called.\n";
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap copy constructor called.\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap got destructed!\n";
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	FragTrap::attack(std::string const & target)
{
	ClapTrap	*clap_target;

	if (this->can_act() == false)
		return ;
	clap_target = find_clap_trap(target);
	if (clap_target == NULL)
	{
		std::cout << "Target " << target << " doesn't exist.\n";
		return ;
	}
	std::cout << "FragTrap " << this->get_name() << " attacks " << clap_target->get_name() \
		<< ", causing " << this->get_attack_damage() << " points of damage!\n";
	clap_target->takeDamage(this->get_attack_damage());
	this->sum_energy_points(-1);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->is_dead())
	{
		std::cout << "FragTrap " << this->get_name() << " is dead!\n";
		return ;
	}
	std::cout << this->get_name() << ": Let's high five guys!?!?!!!" << std::endl;
}
