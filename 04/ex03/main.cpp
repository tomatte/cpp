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
	AMateria	*cure = new Cure();
	Floor		floor;

	floor.add_materia(ice);
	floor.add_materia(cure);
	ice->use(*player);
	cure->use(*player);
	floor.clear_floor();
	return (0);
}
