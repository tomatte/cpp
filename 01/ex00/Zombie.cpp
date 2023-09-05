#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " got destroyed!!!\n";
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

