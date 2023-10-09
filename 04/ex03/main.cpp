#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Floor.hpp"

int	main(void)
{
	ICharacter	*player = new Character("John");
	AMateria	*ice = new Ice();
	AMateria	*ice2 = new Ice();
	AMateria	*cure = new Cure();
	AMateria	*cure2 = new Cure();
	Floor		floor;
	Floor		floor2;

	floor.add_materia(ice);
	floor.add_materia(cure);
	floor2 = floor;
	ice->use(*player);
	cure->use(*player);
	floor.clear_floor();
	floor2.clear_floor();
	return (0);
}
