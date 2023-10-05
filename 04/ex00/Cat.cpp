#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->sound = "Meowwww";
}

Cat::Cat(Cat const & rhs) : Animal(rhs)
{
	this->type = rhs.type;
	this->sound = rhs.sound;
}

Cat::~Cat(void)
{
}

Cat & Cat::operator=(Cat const & rhs)
{
	Animal::operator=(rhs);
	this->type = rhs.type;
	return (*this);
}
