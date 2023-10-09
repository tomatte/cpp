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
	std::cout << "Ice destructor called." << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	(void) rhs;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice	*materia = new Ice(*this);
	return (materia);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	
}
