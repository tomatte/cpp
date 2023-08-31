#include "Blade.class.hpp"
#include <iostream>

Blade::Blade(void) {
    std::cout << "Constructor called" << std::endl;
    return ;
}

Blade::~Blade(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

void Blade::say(void) {
    std::cout << "Blade, o caçador de vampiros!" << std::endl;
    return ;
}
