#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : index(0) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

PhoneBook::PhoneBook(PhoneBook const & rhs) {
	for (int i = 0; i < 8; i++) {
		this->contacts[i] = rhs.contacts[i];
	}
	this->index = rhs.index;
}

int	PhoneBook::has_empty_field(Contact & c) {
	if (c.get_first_name() == "")
		return (1);
	if (c.get_last_name() == "")
		return (1);
	if (c.get_nickname() == "")
		return (1);
	if (c.get_dark_secret() == "")
		return (1);
	if (c.get_phone_number() == "")
		return (1);
	return (0);
}

void	PhoneBook::add_contact(Contact & contact) {
	if (PhoneBook::has_empty_field(contact)) {
		std::cout << "Fail to add contact: empty field" << std::endl;
		return ;
	}
	this->contacts[this->index] = contact;
	this->index++;
	if (this->index > 7)
		this->index = 0;
}

Contact const &	PhoneBook::get_contact(int i) const {
	if (i < 0 || i > 7)
		i = 0;
	return this->contacts[i];
}

void	PhoneBook::print_multiple_char(char c, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << c;
	}
}

int	abs(int num) {
	if (num < 0)
		return (num * -1);
	return (num);
}

void	PhoneBook::print_with_pipe(std::string str) {
	std::string	limited;

	limited = str.substr(0, 10);
	std::cout << "|";
	std::cout << std::right;
	std::cout.width(10);
	if (str.length() > 10)
		limited[9] = '.';
	std::cout << limited;
	//std::cout << "Padding: " << padding << std::endl;
}

void	PhoneBook::print_with_pipe(int index) {
	std::cout << "|";
	std::cout << std::right;
	std::cout.width(10);
	std::cout << index;
}

void	PhoneBook::show_contacts(void) const {
	int			i;

	i = 0;
	std::cout << "---------------------------------------------\n";
	std::cout << "|  INDEX   |FIRST NAME|LAST NAME | NICKNAME |\n";
	std::cout << "|          |          |          |          |\n";
	while (1) {
		if (this->contacts[i].get_first_name() == "")
			break ;
		print_with_pipe(i + 1);
		print_with_pipe(this->contacts[i].get_first_name());
		print_with_pipe(this->contacts[i].get_last_name());
		print_with_pipe(this->contacts[i].get_nickname());
		std::cout << "|\n";
		i++;
		if (i > 7)
			break ;
	}
	std::cout << "---------------------------------------------\n\n";
}
