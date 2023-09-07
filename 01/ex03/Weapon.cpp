/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:33:00 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 19:13:01 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string w_type) : type(w_type) {
}

Weapon::~Weapon(void) {
}

std::string const &	Weapon::getType(void) {
	return (this->type);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}