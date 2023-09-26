/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/26 10:49:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "ft.hpp"
#include "Triangle.hpp"

ft::t_vector	point(float x, float y) {
	ft::t_vector	p;

	p.x = Fixed(x);
	p.y = Fixed(y);
	return (p);
}

bool	is_point_inside_triangle(ft::t_vector point, Triangle & t) {
	Triangle	triangle;
	Fixed	abc_area;
	Fixed	pab_area;
	Fixed	pac_area;
	Fixed	pcb_area;
	Fixed	p_sum;

	abc_area = t.calc_area();

	triangle = t;
	triangle.C = point;
	pab_area = triangle.calc_area();

	triangle = t;
	triangle.B = point;
	pac_area = triangle.calc_area();

	triangle = t;
	triangle.A = point;
	pcb_area = triangle.calc_area();

	p_sum = pab_area + pac_area + pcb_area;
	if (ft::abs(p_sum.toFloat() - abc_area.toFloat()) < 0.1)
		return (true);
	return (false);
}

void	verify_point_is_inside_triangle(ft::t_vector point, Triangle & t) {
	if (is_point_inside_triangle(point, t))
		std::cout << "(" << point.x << ", " << point.y << ") is inside triangle!!! Yeeeeeeeaaahh!!!\n";
	else
		std::cout << "(" << point.x << ", " << point.y << ") is outside triangle :(\n";
}

int	main(void) {
	Triangle	triangle(
		-3, -7,
		10, 0,
		-10, 6
	);

	verify_point_is_inside_triangle(point(-8, 2), triangle);
	verify_point_is_inside_triangle(point(-7, 2), triangle);
	verify_point_is_inside_triangle(point(-6, 2), triangle);
	verify_point_is_inside_triangle(point(2, 2), triangle);
	verify_point_is_inside_triangle(point(2, 3), triangle);
	verify_point_is_inside_triangle(point(9, 0), triangle);
	return (0);
}
