#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & rhs)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		*this->_materias[i] = *rhs._materias[i];
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
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
			this->_materias[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i]->getType() == type)
		{
			if (type == "ice")
				return (new Ice(*this->_materias[i]));
			else
				return (new Cure(*this->_materias[i]));
		}
	}
	return (NULL);
}
