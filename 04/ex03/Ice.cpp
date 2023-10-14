#include "Ice.hpp"
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ft.hpp"
#include "ColorOut.hpp"

Ice::Ice(void) : AMateria("ice")
{
	ColorOut::green << "Ice default constructor called.\n";
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
	(void) rhs;
	ColorOut::green << "Ice copy constructor called.\n";
}

Ice::Ice(AMateria const & rhs) : AMateria(rhs)
{
	(void) rhs;
	ColorOut::green << "Ice materia constructor called.\n";
}

Ice::~Ice(void)
{
	ColorOut::magenta << "Ice destructor called.\n";
}

Ice & Ice::operator=(Ice const & rhs)
{
	std::cout << "Ice copy asignment operator called.\n";
	(void) rhs;
	return (*this);
}

AMateria* Ice::clone() const
{
	std::cout << "Ice cloned.\n";
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	ColorOut::blue_b << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
