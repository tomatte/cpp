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
			return (ClapTrap::clap_traps[i]);
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

ClapTrap::ClapTrap(ClapTrap const & rhs) : 
name(rhs.name), hit_points(rhs.hit_points),
energy_points(rhs.energy_points), attack_damage(rhs.attack_damage)
{
	std::cout << "ClapTrap copy constructor called.\n";
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
		std::cout << this->name << " is dead x_x\n";
		return (false);
	}
	if (this->energy_points <= 0)
	{
		std::cout << this->name << " is so tired!\n";
		return (false);
	}
	return (true);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	std::cout << this->name << " lost " << amount << " hit_points. " \
		<< "Remaining: " << this->hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->can_act() == false)
		return ;
	this->hit_points += amount;
	this->energy_points--;
	std::cout << this->name << " repaired " << amount << " hit_points. " \
		<< "Total: " << this->hit_points << "\n";
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
	std::cout << "ClapTrap " << this->name << " attacks " << clap_target->name \
		<< ", causing " << this->attack_damage << " points of damage!\n";
	clap_target->takeDamage(this->attack_damage);
	this->energy_points--;
}


void	ClapTrap::set_hit_points(int amount)
{
	this->hit_points = amount;
}

void	ClapTrap::set_energy_points(int amount)
{
	this->energy_points = amount;
}

void	ClapTrap::set_attack_damage(int amount)
{
	this->attack_damage = amount;
}

void	ClapTrap::sum_energy_points(int amount)
{
	this->energy_points += amount;
}

std::string	ClapTrap::get_name(void) const
{
	return (this->name);
}

int	ClapTrap::get_attack_damage(void) const
{
	return (this->attack_damage);
}

int	ClapTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int	ClapTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

bool	ClapTrap::is_dead(void) const
{
	return (this->hit_points <= 0);
}
