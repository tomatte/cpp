/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:22:47 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 18:46:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void) {
	Zombie		*horde;
	int			N = 5;

	horde = zombieHorde(N, "James");
	for (int i = 0; i < N; i++) {
		(horde + i)->announce();
	}
	delete [] horde;
	return (0);
}
