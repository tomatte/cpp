#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

void	get_line2(std::string& str) {
	std::getline(std::cin, str);
	if (std::cin.eof()) {
		std::cout << std::endl;
		exit(0);
	}
}

bool only_digits(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void	read_number(std::string& str) {
	while (1) {
		std::cout << "Phone number: ";
		get_line2(str);
		if (only_digits(str) == false)
			std::cout << "Only digits allowed. Try again!\n";
		else
			return ;
	}
}

void	add_contact(PhoneBook & phone_book) {
	Contact		contact;
	std::string	str;

	std::cin.ignore();
	std::cout << "First name: ";
	get_line2(str);
	contact.set_first_name(str);
	std::cout << "Last name: ";
	get_line2(str);
	contact.set_last_name(str);
	std::cout << "Nickname: ";
	get_line2(str);
	contact.set_nickname(str);
	std::cout << "Darkest secret: ";
	get_line2(str);
	contact.set_dark_secret(str);
	read_number(str);
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
		if (std::cin.eof()) {
			std::cout << std::endl;
			std::exit(0);
		}
		if (std::cin.fail()) {
			std::cout << "Invalid index, try again!" << std::endl;
			std::cin.clear();
		}
		else if (index < 1 || index > 8) {
			std::cout << "Index not in range. Try again!" << std::endl;
		}
		else {
			return index;
		}
	}
}

void	search_contact(PhoneBook & phone_book) {
	int	index;

 	phone_book.show_contacts();
	index = read_index();
	phone_book.get_contact(index - 1).show();
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
		else if (command == "ADD")
			add_contact(phone_book);
		else if (command == "SEARCH")
			search_contact(phone_book);
	}
	return (0);
}
