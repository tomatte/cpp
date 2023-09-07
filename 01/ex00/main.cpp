/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:12:22 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:12:22 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
