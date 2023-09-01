#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	Contact	contact;

	contact.set_first_name("Abileu");
	std::cout << "Name: " << contact.get_first_name() << "\n";
	return (0);
}
