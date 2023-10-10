#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Floor.hpp"

int	main(void)
{
	Character	player1("Rafa");
	Character	player2("Pedro");

	player1.equip(new Ice());
	player1.equip(new Cure());
	player2 = player1;
	player2.use(0, player1);
	player2.use(1, player1);
	player2.use(2, player1);

	AMateria::floor.clear_floor();
	return (0);
}
