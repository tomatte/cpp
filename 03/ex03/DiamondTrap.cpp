#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
FragTrap(), ScavTrap(), name(name)
{
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(30);
	std::cout << "DiamondTrap string constructor called!\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructed!\n";
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
