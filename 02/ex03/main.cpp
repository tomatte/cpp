/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/24 07:34:16 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "ft.hpp"

Fixed	matrix_determinant(Fixed matrix[3][5]) {
	std::cout << matrix[0][0] << std::endl;
	std::cout << matrix[0][1] << std::endl;
	return Fixed(1);
}

int	main(void) {
	Fixed	matrix[3][5];

	matrix[0][0] = 29;
	matrix[0][1] = 1.11f;
	matrix_determinant(matrix);
	return (0);
}
