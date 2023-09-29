#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap constructed.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
	std::cout << "FragTrap constructed.\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap got destructed!\n";
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

void	FragTrap::guardGate(void)
{
	if (this->in_gate_keeper_mode == true)
	{
		std::cout << "FragTrap " << this->get_name() << " is already in Gate keeper mode!\n";
		return ;
	}
	std::cout << "FragTrap " << this->get_name() << " is now in Gate keeper mode.\n";
	this->set_attack_damage(this->get_attack_damage() / 2);
	this->sum_energy_points(100);
	this->set_hit_points(500);
}
