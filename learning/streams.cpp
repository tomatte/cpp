#include <iostream>

int main(void) {
    char    buff[256];

    std::cout << "Hello, world!" << std::endl;
    std::cout << std::endl << "A word: ";
    std::cin >> buff;
    std::cout << "The word is: " << buff << std::endl;
    return 0;
}