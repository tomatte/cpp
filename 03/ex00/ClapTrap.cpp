#include "ClapTrap.hpp"
#include <iostream>

int	ClapTrap::total = 0;

ClapTrap::ClapTrap(void) : name(""), hit_points(10), 
energy_points(10), attack_damage(0) {
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), 
energy_points(10), attack_damage(0) {
	ClapTrap::total++;
	ClapTrap::clap_traps[ClapTrap::total - 1] = this;
}

void	ClapTrap::attack(std::string const & target) {

}