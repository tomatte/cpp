#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const & rhs) : WrongAnimal(rhs)
{
	this->type = rhs.type;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	WrongAnimal::operator=(rhs);
	this->type = rhs.type;
	std::cout << "WrongCat copy asignment operator called." << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meowwwdlskajnda" << std::endl;
}
