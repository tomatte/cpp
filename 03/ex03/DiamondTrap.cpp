#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap(),
FragTrap(), ScavTrap()
{
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(30);
	std::cout << "DiamondTrap default constructor called!\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
FragTrap(), ScavTrap(), name(name)
{
	this->set_hit_points(FragTrap::hit_points);
	this->set_energy_points(ScavTrap::energy_points);
	this->set_attack_damage(FragTrap::attack_damage);
	std::cout << "FragAttack: " << FragTrap::attack_damage << "\n";
	std::cout << "DiamondTrap string constructor called!\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs) :
ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs), name(rhs.name)
{
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructed!\n";
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	this->name = rhs.name;
	ClapTrap::operator=(rhs);
	ScavTrap::operator=(rhs);
	FragTrap::operator=(rhs);
	return (*this);
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << " and " << ClapTrap::get_name() << "\n";
}
