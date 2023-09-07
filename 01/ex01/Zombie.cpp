/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:22:41 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:22:42 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
	std::cout << "Default constructor: Danger!!! Zombie spawned!\n";
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Parameter constructor: Danger!!! Zombie spawned!\n";
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " got destroyed!!!\n";
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}
