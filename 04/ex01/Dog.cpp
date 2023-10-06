#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(Dog const & rhs) : Animal(rhs)
{
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called." << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	Animal::operator=(rhs);
	this->type = rhs.type;
	*this->brain = *rhs.brain;
	std::cout << "Dog copy asignment operator called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!!!" << std::endl;
}

void	Dog::set_idea(int index, std::string const & idea)
{
	if (index >= 100 || index < 0)
		return ;
	this->brain->set_idea(index, idea);
}

std::string	Dog::get_idea(int index) const
{
	return (this->brain->get_idea(index));
}
