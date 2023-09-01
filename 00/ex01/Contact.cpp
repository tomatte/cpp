#include "Contact.hpp"
#include <string>

Contact::Contact(void) : first_name("") {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::get_first_name(void) const {
	return this->first_name;
}

std::string	Contact::get_last_name(void) const {
	return this->last_name;
}

std::string	Contact::get_nickname(void) const {
	return this->nickname;
}

std::string	Contact::get_dark_secret(void) const {
	return this->dark_secret;
}

std::string	Contact::get_phone_number(void) const {
	return this->phone_number;
}

void	Contact::set_first_name(std::string name) {
	this->first_name = name;
	return ;
}

void	Contact::set_last_name(std::string name) {
	this->last_name = name;
	return ;
}

void	Contact::set_nickname(std::string name) {
	this->nickname = name;
	return ;
}

void	Contact::set_phone_number(std::string number) {
	this->phone_number = number;
	return ;
}
