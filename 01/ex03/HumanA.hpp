/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:32:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:32:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {
	Weapon &	weapon;
	std::string	name;
	public:
		HumanA(std::string name, Weapon & w);
		~HumanA(void);
	
		void	attack(void) const;
};

#endif