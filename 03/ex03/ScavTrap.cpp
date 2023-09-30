#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
	std::cout << "ScavTrap constructed.\n";
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs),
in_gate_keeper_mode(rhs.in_gate_keeper_mode)
{
	std::cout << "ScavTrap copy constructor called.\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap got destructed!\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
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
	std::cout << "ScavTrap " << this->get_name() << " attacks " << clap_target->get_name() \
		<< ", causing " << this->get_attack_damage() << " points of damage!\n";
	clap_target->takeDamage(this->get_attack_damage());
	this->sum_energy_points(-1);
}

void	ScavTrap::guardGate(void)
{
	if (this->is_dead())
	{
		std::cout << "ScavTrap " << this->get_name() << " is dead!\n";
		return ;
	}
	if (this->in_gate_keeper_mode == true)
	{
		std::cout << "ScavTrap " << this->get_name() << " is already in Gate keeper mode!\n";
		return ;
	}
	std::cout << "ScavTrap " << this->get_name() << " is now in Gate keeper mode.\n";
	this->in_gate_keeper_mode = true;
	this->set_attack_damage(this->get_attack_damage() / 2);
	this->sum_energy_points(100);
	this->set_hit_points(500);
}
