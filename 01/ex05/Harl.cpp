/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:01:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 08:01:56 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "messages.hpp"
#include <string>
#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << DEBUG << "\n";
}

void	Harl::info(void) {
	std::cout << INFO << "\n";
}

void	Harl::warning(void) {
	std::cout << WARNING << "\n";
}

void	Harl::error(void) {
	std::cout << ERROR << "\n";
}

void	Harl::complain(std::string level) {
	void	(Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string const	options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		level == options[i] ? (this->*funcs[i])() : (void)0;
	}
}
