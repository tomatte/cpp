#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(int p1, char p2, int p3) : age(p1), letter(p2), money(p3) {
    std::cout << "Constructor called" << std::endl; 
    std::cout << "Age: " << p1 << " Letter: " << p2 << " Money: " << money << std::endl;
    return ;
}

Sample::~Sample(void) {
    std::cout << "Destructor called!" << std::endl;
    return ;
}
