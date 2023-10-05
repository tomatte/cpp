#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const & rhs) : Animal(rhs)
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->type = rhs.type;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->brain;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog copy asignment operator called." << std::endl;
	Animal::operator=(rhs);
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!!!" << std::endl;
}
