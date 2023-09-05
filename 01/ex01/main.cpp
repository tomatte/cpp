#include "Zombie.hpp"

Zombie*	zombieHorde(int const N, std::string name) {
	Zombie	*zombies;

	zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		(zombies + i)->setName(name);
	}
	return (zombies);
}

void	hordeAnnounce(int const N, Zombie *horde) {
	for (int i = 0; i < N; i++) {
		(horde + i)->announce();
	}
}

int	main(void) {
	Zombie		*horde;
	int const	N = 4;

	horde = zombieHorde(N, "James");
	hordeAnnounce(N, horde);
	delete [] horde;
	return (0);
}
