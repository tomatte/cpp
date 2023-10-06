#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
{
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
}

Ice::~Ice(void)
{
}

Ice & Ice::operator=(Ice const & rhs)
{

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
