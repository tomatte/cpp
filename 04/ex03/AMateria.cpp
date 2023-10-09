#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>
#include "ICharacter.hpp"

Floor	*AMateria::floor = NULL;

void	AMateria::init_floor(void)
{
	if (AMateria::floor == NULL)
		AMateria::floor = new Floor();
}

AMateria::AMateria(void)
{
	AMateria::init_floor();
}

AMateria::AMateria(std::string const & type) : type(type)
{
	AMateria::init_floor();
}

AMateria::AMateria(AMateria const & rhs) : type(rhs.type)
{
	AMateria::init_floor();
}

AMateria::~AMateria(void)
{
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	(void) rhs;
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
