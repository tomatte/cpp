#include "Floor.hpp"
#include "ft.hpp"
#include "AMateria.hpp"

Floor::Floor(void) : materias(NULL)
{
}

Floor::Floor(Floor const & rhs)
{
	this->materias = ft::dup_list(rhs.materias);
}

Floor::~Floor(void)
{
}

Floor & Floor::operator=(Floor const & rhs)
{
	this->materias = ft::dup_list(rhs.materias);
	return (*this);
}

void	Floor::add_materia(AMateria *materia)
{
	ft::add_to_list(&this->materias, materia);
}

void	Floor::clear_floor(void)
{
	ft::clear_list(&this->materias);
}
