#include "Ice.hpp"
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
}

Ice::Ice(AMateria const & rhs) : AMateria(rhs)
{
}

Ice::~Ice(void)
{
}

Ice & Ice::operator=(Ice const & rhs)
{
	(void) rhs;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
