#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>
#include "ICharacter.hpp"
#include "ColorOut.hpp"

Floor	AMateria::floor;

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria string constructor called." << std::endl;
}

AMateria::AMateria(AMateria const & rhs) : type(rhs.type)
{
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::~AMateria(void)
{
	ColorOut::magenta << "AMateria destructor called." << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	ColorOut::none << "AMateria copy asignment operator called." << std::endl;
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
