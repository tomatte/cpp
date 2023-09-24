/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/24 08:56:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "ft.hpp"
#include "Triangle.hpp"

Fixed	matrix_determinant(Fixed matrix[3][5]) {
	std::cout << matrix[0][0] << std::endl;
	std::cout << matrix[0][1] << std::endl;
	return Fixed(1);
}

int	main(void) {
	Triangle	triangle;

	triangle.A.x = 1;
	triangle.A.y = 2;
	triangle.B.x = 3;
	triangle.B.y = 3;
	triangle.C.x = 0;
	triangle.C.y = 5;

	std::cout << "determinant: " << triangle.calc_triangle_determinant() << std::endl;
	return (0);
}
