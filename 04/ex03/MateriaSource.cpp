#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"
#include "ColorOut.hpp"

MateriaSource::MateriaSource(void)
{
	ColorOut::green << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & rhs)
{
	ColorOut::green << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		*this->_materias[i] = *rhs._materias[i];
}

MateriaSource::~MateriaSource(void)
{
	ColorOut::magenta << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	ColorOut::none << "MateriaSource copy asignment operator called." << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (rhs._materias[i] == NULL)
			continue ;
		if (rhs._materias[i]->getType() == "ice")
			this->_materias[i] = new Ice(*rhs._materias[i]);
		else
			this->_materias[i] = new Cure(*rhs._materias[i]);
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i] == NULL)
		{
			ColorOut::yellow << "MateriaSource learned " << m->getType() << "." << std::endl;
			this->_materias[i] = m;
			return ;
		}
	}
	AMateria::floor.add_materia(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i]->getType() == type)
		{
			ColorOut::yellow << "MateriaSource is creating " << type << "." << std::endl;
			if (type == "ice")
				return (new Ice(*this->_materias[i]));
			else
				return (new Cure(*this->_materias[i]));
		}
	}
	return (NULL);
}
