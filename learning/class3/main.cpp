#include "Jay.class.hpp"
#include <iostream>

int main(void) {
    Jay *jay;

    jay = new Jay(15);
    std::cout << "Age: " << jay->get_age() << std::endl;
    delete jay;
    return 0;
}
