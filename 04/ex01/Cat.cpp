#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const & rhs) : Animal(rhs)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->type = rhs.type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat copy asignment operator called." << std::endl;
	Animal::operator=(rhs);
	this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowww" << std::endl;
}
