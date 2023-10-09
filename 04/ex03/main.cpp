#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ft.hpp"

int	main(void)
{
	ft::t_lst	*list = NULL;
	ICharacter	*player = new Character("John");
	AMateria	*ice = new Ice();
	AMateria	*ice2 = new Ice();

	ft::add_to_list(&list, ice);
	ft::add_to_list(&list, ice2);
	ice->use(*player);

	ft::clear_list(&list);
	return (0);
}
