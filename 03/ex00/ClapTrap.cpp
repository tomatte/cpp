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
	std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), 
energy_points(10), attack_damage(0)
{
	store_clap_trap(this);
	std::cout << "ClapTrap constructed.\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructed.\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

bool	ClapTrap::can_act(void) const
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead x_x\n";
		return (false);
	}
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is so tired!\n";
		return (false);
	}
	return (true);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " lost " << amount << " hit_points.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->can_act() == false)
		return ;
	this->hit_points += amount;
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " repaired " << amount << " hit_points.\n";
}

void	ClapTrap::attack(std::string const & target)
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
	clap_target->takeDamage(this->attack_damage);
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << clap_target->name \
		<< ", causing " << this->attack_damage << " points of damage!\n";
}
