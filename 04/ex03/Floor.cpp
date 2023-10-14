#include "Floor.hpp"
#include "ft.hpp"
#include "AMateria.hpp"
#include "ColorOut.hpp"

Floor::Floor(void) : materias(NULL)
{
	ColorOut::green << "Floor default constructor called." << std::endl;
}

Floor::Floor(Floor const & rhs)
{
	ColorOut::green << "Floor copy constructor called." << std::endl;
	this->materias = ft::dup_list(rhs.materias);
}

Floor::~Floor(void)
{
	ColorOut::magenta << "Floor destructor called." << std::endl;
}

Floor & Floor::operator=(Floor const & rhs)
{
	ColorOut::none << "Floor copy asignment operator called." << std::endl;
	this->materias = ft::dup_list(rhs.materias);
	return (*this);
}

void	Floor::add_materia(AMateria *materia)
{
	if (materia == NULL)
		return ;
	ColorOut::red << materia->getType() << " was thrown in the floor" << std::endl;
	ft::add_to_list(&this->materias, materia);
}

void	Floor::clear_floor(void)
{
	ColorOut::yellow << "Cleaning the floor..." << std::endl;
	ft::clear_list(&this->materias);
	ColorOut::yellow << "Floor is clean!!!" << std::endl;
}
