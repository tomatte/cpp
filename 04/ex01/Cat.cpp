#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(Cat const & rhs) : Animal(rhs)
{
	this->type = rhs.type;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	Animal::operator=(rhs);
	this->type = rhs.type;
	std::cout << "Cat copy asignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowww" << std::endl;
}
