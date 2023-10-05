#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : type("")
{

}

Animal::Animal(Animal const & rhs) : type(rhs.type)
{

}

Animal::~Animal(void)
{
}

Animal & Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "a" << std::endl;
}
