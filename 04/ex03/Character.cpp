#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"

void	Character::clear_inventory(AMateria *_invetory[MAX_ITEMS])
{
	for (int i = 0; i < MAX_ITEMS; i++)
		_invetory[i] = NULL;
}

Character::Character(Character const & rhs) : _name(rhs._name), _items(rhs._items)
{
	for (int i = 0; i < MAX_ITEMS; i++)
		*this->_invetory[i] = *rhs._invetory[i];
}
Character::Character(std::string const & name) : _name(name), _items(0)
{
	Character::clear_inventory(this->_invetory);
}

Character::Character(void) : _name(""), _items(0)
{
	Character::clear_inventory(this->_invetory);
}

Character::~Character(void)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (this->_invetory[i] != NULL)
			delete this->_invetory[i];
	}
}

Character & Character::operator=(Character const & rhs)
{
	this->_name = rhs._name;
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
			this->_invetory[i] = m;
			return ;
		}
	}
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
	this->_invetory[idx]->use(target);
}
