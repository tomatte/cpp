#include <string>
#include <iostream>

int	main(void) {
	std::string	brain("HI THIS IS BRAIN");
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "brain address: " << &brain << "\n";
	std::cout << "stringPTR: " << stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n";
	
	std::cout << "brain value: " << brain << "\n";
	std::cout << "stringPTR pointed to: " << *stringPTR << "\n";
	std::cout << "stringREF pointed to: " << stringREF << "\n";
	return (0);
}
