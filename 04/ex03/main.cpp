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
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	player->equip(ice);
	player2->equip(cure);
	player->use(0, *player2);
	player2->use(0, *player2);
	player->unequip(0);
	AMateria::floor->clear_floor();
	delete AMateria::floor;
	delete player2;
	delete player;
	return (0);
}
