#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(Cat const & rhs) : AAnimal(rhs)
{
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	AAnimal::operator=(rhs);
	this->type = rhs.type;
	*this->brain = *rhs.brain;
	std::cout << "Cat copy asignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowww" << std::endl;
}

void	Cat::set_idea(int index, std::string const & idea)
{
	if (index >= 100 || index < 0)
		return ;
	this->brain->set_idea(index, idea);
}

std::string	Cat::get_idea(int index) const
{
	return (this->brain->get_idea(index));
}
