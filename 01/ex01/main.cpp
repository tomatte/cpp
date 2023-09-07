/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:22:47 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:26:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int const N, std::string name);

int	main(void) {
	Zombie		*horde;
	int const	N = 5;

	horde = zombieHorde(N, "James");
	for (int i = 0; i < N; i++) {
		(horde + i)->announce();
	}
	delete [] horde;
	return (0);
}
