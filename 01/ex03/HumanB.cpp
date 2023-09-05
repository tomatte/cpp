#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string h_name) : weapon(NULL), name(h_name) {
}

HumanB::~HumanB(void) {
}

void	HumanB::attack(void) const {
	std::cout << this->name << " attacks with their ";
	if (this->weapon == NULL)
		std::cout << "hands" << "\n";
	else
		std::cout << (*this->weapon).getType() << "\n";
}

void	HumanB::setWeapon(Weapon & w) {
	this->weapon = &w;
}
