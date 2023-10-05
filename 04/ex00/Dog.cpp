#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->sound = "Woof Woof";
}

Dog::Dog(Dog const & rhs) : Animal(rhs)
{
	this->type = rhs.type;
	this->sound = rhs.sound;
}

Dog::~Dog(void)
{
}

Dog & Dog::operator=(Dog const & rhs)
{
	Animal::operator=(rhs);
	this->type = rhs.type;
	return (*this);
}
