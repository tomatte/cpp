/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:02:03 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 08:02:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
#include <string>

class Harl {
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	int		x;
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};

#endif