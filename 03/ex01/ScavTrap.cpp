#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap string constructor called.\n";
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs),
in_gate_keeper_mode(rhs.in_gate_keeper_mode)
{
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "ScavTrap copy constructor called.\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap got destructed!\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	this->in_gate_keeper_mode = rhs.in_gate_keeper_mode;
	return (*this);
}

void	ScavTrap::attack(std::string const & target)
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
	std::cout << "ScavTrap " << this->name << " attacks " << clap_target->get_name() \
		<< ", causing " << this->attack_damage << " points of damage!\n";
	clap_target->takeDamage(this->attack_damage);
	this->energy_points--;
}

void	ScavTrap::guardGate(void)
{
	if (this->in_gate_keeper_mode == true)
	{
		std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode!\n";
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode.\n";
	this->attack_damage /= 2;
	this->energy_points = 100;
	this->hit_points = 500;
}
