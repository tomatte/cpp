#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : type(""), sound("")
{

}

Animal::Animal(Animal const & rhs) : type(rhs.type), sound(rhs.sound)
{

}

Animal::~Animal(void)
{
}

Animal & Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	this->sound = rhs.sound;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << this->sound << std::endl;
}
