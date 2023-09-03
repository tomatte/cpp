#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void	add_contact(PhoneBook & phone_book) {
	Contact		contact;
	std::string	str;

	std::cin.ignore();
	std::cout << "First name: ";
	std::getline(std::cin, str);
	contact.set_first_name(str);
	std::cout << "Last name: ";
	std::getline(std::cin, str);
	contact.set_last_name(str);
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	contact.set_nickname(str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	contact.set_dark_secret(str);
	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	contact.set_phone_number(str);
	phone_book.add_contact(contact);
	return ;
}

int	read_index(void) {
	int	index;

	while (1) {
		std::cout << "Index: " << std::flush;
		std::cin.ignore();
		std::cin >> index;
		if (std::cin.fail()) {
			std::cout << "Invalid index, try again!" << std::endl;
		}
		else if (index < 1 || index > 8) {
			std::cout << "Index not in range. Try again!" << std::endl;
		}
		else
			return index;
	}
}

void	search_contact(PhoneBook & phone_book) {
	int	index;

 	phone_book.show_contacts();
	index = read_index();
	std::cout << "FOUND: " << phone_book.get_contact(index - 1).get_first_name() << "\n";
}

int	main(void) {
	PhoneBook	phone_book;
	std::string	command;

	while (1) {
		std::cout << "COMMANDS: [EXIT, SEARCH, ADD]\n";
		std::cout << "> ";
		std::cin >> command;
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (0);
		}
		if (command == "EXIT")
			return (0);
		if (command == "ADD")
			add_contact(phone_book);
		if (command == "show")
			phone_book.show_contacts();
		if (command == "SEARCH")
			search_contact(phone_book);
	}
	return (0);
}
