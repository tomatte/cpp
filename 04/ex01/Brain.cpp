#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(Brain const & rhs)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (size_t i = 0; i < rhs.ideas->length(); i++)
		this->ideas[i] = rhs.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain &	Brain::operator=(Brain const & rhs)
{
	for (size_t i = 0; i < rhs.ideas->length(); i++)
		this->ideas[i] = rhs.ideas[i];
	std::cout << "Brain copy asignment operator called." << std::endl;
	return (*this);
}
