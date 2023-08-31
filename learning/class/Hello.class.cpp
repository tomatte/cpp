#include "Hello.class.hpp"
#include <iostream>

Hello::Hello(void) {
    std::cout << "Constructor called" << std::endl;
    return ;
}

Hello::~Hello(void) {
    std::cout << "Destructor called!" << std::endl;
    return ;
}