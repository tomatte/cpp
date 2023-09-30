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
	std::cout << "DiamondTrap string constructor called!\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructed!\n";
}
