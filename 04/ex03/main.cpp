#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Floor.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "---------- Subject test ----------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	/////////////////////////////////////////////////////////////
	std::cout << "\n---------- My Tests ----------" << std::endl;
	Character	soraka("Soraka");
	Character	anivia("Anivia");

	std::cout << "Soraka equip its cures\n";
	soraka.equip(new Cure());
	soraka.equip(new Cure());
	soraka.equip(new Cure());

	std::cout << "Anivia try to equip 10 ices, but have slot for only 4, the others fall in the floor\n";
	for (int i = 0; i < 10; i++)
		anivia.equip(new Ice());

	std::cout << "\nAnivia uses it's ice against Soraka\n";
	anivia.use(0, soraka);

	std::cout << "\nSoraka heals herself and Anivia ???\n";
	soraka.use(2, soraka);
	soraka.use(1, anivia);

	std::cout << "\nunequip all soraka's materias\n";
	for (int i = 0; i < 4; i++)
		soraka.unequip(i);

	std::cout << "tries to use materia in an empty slot, but do nothing\n";
	soraka.use(0, soraka);
	soraka.use(1, anivia);

	std::cout << "\nmateria_source learns 4 materias: 3 cures and 1 ice\n";
	IMateriaSource	*materia_source = new MateriaSource();
	materia_source->learnMateria(new Cure());
	materia_source->learnMateria(new Cure());
	materia_source->learnMateria(new Cure());
	materia_source->learnMateria(new Ice());

	std::cout << "soraka equips ice through materia_source and use it against anivia\n";
	soraka.equip(materia_source->createMateria("ice"));
	soraka.use(0, anivia);

	delete materia_source;
	AMateria::floor.clear_floor();
	return 0;
}