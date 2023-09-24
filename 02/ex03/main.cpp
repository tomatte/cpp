/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/24 13:20:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "ft.hpp"
#include "Triangle.hpp"

Triangle	just_a_triangle(void) {
	Triangle	triangle;

	triangle.A.x = 1;
	triangle.A.y = 2;
	triangle.B.x = 3;
	triangle.B.y = 3;
	triangle.C.x = 0;
	triangle.C.y = 5;
	return (triangle);
}

int	main(void) {
	Triangle	triangle(just_a_triangle());

	std::cout << "area: " << triangle.calc_area() << std::endl;
	return (0);
}
