#include "Contact.hpp"
#include <string>
#include <iostream>

Contact::Contact(void) : _first_name("") {
	return ;
}

Contact::Contact(Contact const & rhs) : _first_name(rhs._first_name),
_last_name(rhs._last_name), _nickname(rhs._nickname),
_dark_secret(rhs._dark_secret), _phone_number(rhs._phone_number) {
}

Contact &	Contact::operator=(Contact const & rhs) {
	this->_first_name = rhs._first_name;
	this->_last_name = rhs._last_name;
	this->_nickname = rhs._nickname;
	this->_dark_secret = rhs._dark_secret;
	this->_phone_number = rhs._phone_number;
	return (*this);
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::get_first_name(void) const {
	return this->_first_name;
}

std::string	Contact::get_last_name(void) const {
	return this->_last_name;
}

std::string	Contact::get_nickname(void) const {
	return this->_nickname;
}

std::string	Contact::get_dark_secret(void) const {
	return this->_dark_secret;
}

std::string	Contact::get_phone_number(void) const {
	return this->_phone_number;
}

void	Contact::set_first_name(std::string name) {
	this->_first_name = name;
	return ;
}

void	Contact::set_last_name(std::string name) {
	this->_last_name = name;
	return ;
}

void	Contact::set_nickname(std::string name) {
	this->_nickname = name;
	return ;
}

void	Contact::set_phone_number(std::string number) {
	this->_phone_number = number;
	return ;
}

void	Contact::set_dark_secret(std::string secret) {
	this->_dark_secret = secret;
}

void	Contact::show(void) const {
	std::cout << "------------- CONTACT -------------\n";
	std::cout << "First name: " << this->_first_name << "\n";
	std::cout << "Last name: " << this->_last_name << "\n";
	std::cout << "Nickname: " << this->_nickname << "\n";
	std::cout << "Darkest secret: " << this->_dark_secret << "\n";
	std::cout << "Phone number: " << this->_phone_number << "\n";
	std::cout << "------------------------------------\n";
}
