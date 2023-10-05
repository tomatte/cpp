#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(Dog const & rhs) : Animal(rhs)
{
	this->type = rhs.type;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	Animal::operator=(rhs);
	this->type = rhs.type;
	std::cout << "Dog copy asignment operator called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!!!" << std::endl;
}
