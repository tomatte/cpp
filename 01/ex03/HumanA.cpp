#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string h_name, Weapon & w) : weapon(w), name(h_name) {
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}
