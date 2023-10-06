#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const & rhs) : type(rhs.type)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	this->type = rhs.type;
	std::cout << "AAnimal copy asignment operator called." << std::endl;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "a" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}
