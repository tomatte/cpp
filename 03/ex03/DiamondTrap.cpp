#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{

}

DiamondTrap::DiamondTrap(std::string name) : 
FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->name = name;
	std::cout << "DiamondTrap constructed!\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructed!\n";
}
