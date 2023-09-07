/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:22:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 18:48:20 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*zombies;

	zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		(zombies + i)->setName(name);
	}
	return (zombies);
}
