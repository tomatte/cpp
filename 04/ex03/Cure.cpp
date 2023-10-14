#include "Cure.hpp"
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ColorOut.hpp"

Cure::Cure(void) : AMateria("cure")
{
	ColorOut::green << "Cure created.\n";
}

Cure::Cure(Cure const & rhs) : AMateria(rhs)
{
	ColorOut::green << "Cure copy constructor called.\n";
}

Cure::Cure(AMateria const & rhs) : AMateria(rhs)
{
	ColorOut::green << "Cure created through another cure.\n";
}

Cure::~Cure(void)
{
	ColorOut::magenta << "Cure destructed.\n";
}

Cure & Cure::operator=(Cure const & rhs)
{
	std::cout << "Cure copy asignment operator called.\n";
	(void) rhs;
	return (*this);
}

AMateria* Cure::clone() const
{
	ColorOut::yellow << "Cure cloned.\n";
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	ColorOut::green_b << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
