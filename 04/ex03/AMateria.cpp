#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"

AMateria::AMateria(void)
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(AMateria const & rhs) : type(rhs.type)
{
}

AMateria::~AMateria(void)
{
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	return (*this);
}


std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* use materia on " << target.getName() << " *"<< std::endl;
}
