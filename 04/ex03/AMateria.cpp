#include "AMateria.hpp"
#include <iostream>

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

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "materia" << std::endl;
}

void	AMateria::put_on_ground(AMateria *m)
{

}