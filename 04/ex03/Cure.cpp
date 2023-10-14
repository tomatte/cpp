#include "Cure.hpp"
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ColorOut.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const & rhs) : AMateria(rhs)
{
}

Cure::Cure(AMateria const & rhs) : AMateria(rhs)
{
}

Cure::~Cure(void)
{
}

Cure & Cure::operator=(Cure const & rhs)
{
	(void) rhs;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	ColorOut::green_b << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
