#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include "ColorOut.hpp"

void	Character::clear_inventory(AMateria *_invetory[MAX_ITEMS])
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (_invetory[i] != NULL)
		{
			delete _invetory[i];
			_invetory[i] = NULL;
		}
	}
}

Character::Character(Character const & rhs) : _name(rhs._name)
{
	ColorOut::green << "Character copy constructor called." << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++)
		*this->_invetory[i] = *rhs._invetory[i];
}
Character::Character(std::string const & name) : _name(name)
{
	ColorOut::green << "Character string constructor called." << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++)
		this->_invetory[i] = NULL;
}

Character::Character(void) : _name("")
{
	ColorOut::green << "Character default constructor called." << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++)
		this->_invetory[i] = NULL;
}

Character::~Character(void)
{
	ColorOut::magenta << "Character destructor called." << std::endl;
	Character::clear_inventory(this->_invetory);
}

Character & Character::operator=(Character const & rhs)
{
	ColorOut::none << "Character copy asignment operator called." << std::endl;
	this->_name = rhs._name;
	Character::clear_inventory(this->_invetory);
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (rhs._invetory[i] == NULL)
			continue ;
		if (rhs._invetory[i]->getType() == "ice")
			this->_invetory[i] = new Ice(*rhs._invetory[i]);
		else
			this->_invetory[i] = new Cure(*rhs._invetory[i]);
	}
	return (*this);
}

std::string	const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (this->_invetory[i] == NULL)
		{
			ColorOut::yellow << this->_name << " equiped " << m->getType() << "." << std::endl;
			this->_invetory[i] = m;
			return ;
		}
	}
	AMateria::floor.add_materia(m);
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_ITEMS)
		return ;
	AMateria::floor.add_materia(this->_invetory[idx]);
	this->_invetory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_ITEMS)
		return ;
	if (this->_invetory[idx])
		this->_invetory[idx]->use(target);
}
