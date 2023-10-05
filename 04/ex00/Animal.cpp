#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const & rhs) : type(rhs.type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor constructor called." << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	std::cout << "Animal copy asignment operator called." << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "a" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
