/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:22:38 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:22:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce( void );
		void	setName(std::string name);
};

#endif