#include "Weapon.hpp"

Weapon::Weapon(std::string w_type) : type(w_type) {
}

Weapon::~Weapon(void) {
}

std::string &	Weapon::getType(void) {
	return (this->type);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}