/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/24 14:33:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "ft.hpp"
#include "Triangle.hpp"
#include <cmath>

ft::t_vector	point(float x, float y) {
	ft::t_vector	p;

	p.x = Fixed(x);
	p.y = Fixed(y);
	return (p);
}

Triangle	just_a_triangle(
		float ax, float ay,
		float bx, float by,
		float cx, float cy
	) {
	Triangle	triangle;

	triangle.A.x = ax;
	triangle.A.y = ay;
	triangle.B.x = bx;
	triangle.B.y = by;
	triangle.C.x = cx;
	triangle.C.y = cy;
	return (triangle);
}

int	verify_point_is_inside_triangle(ft::t_vector point, Triangle & t) {
	Triangle	triangle(t);
	Fixed	abc_area;
	Fixed	pab_area;
	Fixed	pac_area;
	Fixed	pcb_area;
	Fixed	p_sum;

	abc_area = triangle.calc_area();
	triangle.C = point;
	pab_area = triangle.calc_area();
	triangle.C = t.C;
	triangle.B = point;
	pac_area = triangle.calc_area();
	triangle.B = t.B;
	triangle.A = point;
	pcb_area = triangle.calc_area();
	triangle.A = t.A;
	p_sum = pab_area + pac_area + pcb_area;
	if (ft::abs(p_sum.toFloat() - abc_area.toFloat()) < 0.1) {
		std::cout << "(" << point.x << ", " << point.y << ") is inside triangle!!!\n";
		return (1);
	}
	std::cout << "(" << point.x << ", " << point.y << ") is outside triangle.\n";
	return (0);
}

int	main(void) {
	Triangle	triangle(just_a_triangle(
		-3, -7,
		10, 0,
		-10, 6
	));

	verify_point_is_inside_triangle(point(-8, 2), triangle);
	verify_point_is_inside_triangle(point(-7, 2), triangle);
	verify_point_is_inside_triangle(point(-6, 2), triangle);
	verify_point_is_inside_triangle(point(2, 2), triangle);
	verify_point_is_inside_triangle(point(2, 3), triangle);
	verify_point_is_inside_triangle(point(9, 0), triangle);
	return (0);
}
