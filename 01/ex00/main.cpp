#include "Zombie.hpp"

Zombie	*newZombie(std::string name) {
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	return (new_zombie);
}

void randomChump( std::string name ) {
	Zombie	chump(name);

	chump.announce();
}


int	main(void) {
	Zombie	*z1;

	z1 = newZombie("Jhon");
	z1->announce();
	randomChump("Sofia");
	delete z1;
}
