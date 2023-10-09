#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Floor.hpp"

int	main(void)
{
	ICharacter	*player = new Character("John");
	AMateria	*ice = new Ice();
	AMateria	*ice2 = new Ice();
	Floor		floor;
	Floor		floor2;

	floor.add_materia(ice);
	floor.add_materia(ice2);
	floor2 = floor;
	ice->use(*player);
	floor.clear_floor();
	floor2.clear_floor();
	return (0);
}
