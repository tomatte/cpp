#include "Jay.class.hpp"
#include <iostream>

Jay::Jay(int age) {
    this->age = age;
    std::cout << "Constructor called" << std::endl;
    return ;
}

Jay::~Jay(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Jay::get_age(void) {
    return this->age;
}
