#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & rhs) : type(rhs.type)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->type = rhs.type;
	std::cout << "WrongAnimal copy asignment operator called." << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "raw" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
