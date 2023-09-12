/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:12:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/12 09:15:51 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

namespace ft {
	int	pow(int num, int power)
	{
		int	i;
		int	result;

		if (!power)
			return (1);
		result = 1;
		i = 0;
		while (i++ < power)
			result *= num;
		return (result);
	}

	int	abs(int number) {
		if (number < 0)
			return (number * -1);
		return (number);
	}
}
