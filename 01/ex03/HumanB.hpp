/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:32:39 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 18:49:52 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {
	private:
		Weapon *	weapon;
		std::string	name;

	public:
		HumanB(std::string name);
		~HumanB(void);
	
		void	attack(void) const;
		void	setWeapon(Weapon & w);
};

#endif