/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:32:31 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:32:32 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string h_name, Weapon & w) : weapon(w), name(h_name) {
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}
