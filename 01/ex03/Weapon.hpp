/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:33:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 19:12:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string w_type);
		~Weapon(void);

		std::string const &	getType(void);
		void	setType(std::string new_type);
};

#endif