#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Floor.hpp"

int	main(void)
{
	ICharacter	*player = new Character("John");
	ICharacter	*player2 = new Character("Max");

	player->equip(new Ice());
	player->equip(new Cure());
	player2->equip(new Cure());
	player->use(0, *player2);
	player2->use(0, *player2);
	player->unequip(0);
	player2->unequip(0);
	AMateria::floor.clear_floor();
	delete player2;
	delete player;
	return (0);
}
