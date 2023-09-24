#include "Triangle.hpp"

Triangle::Triangle(void) {
}

Triangle::Triangle(Triangle const & rhs) : A(rhs.A), B(rhs.B), C(rhs.C) {
}

Triangle::~Triangle(void) {
}

Fixed Triangle::calc_triangle_determinant(void) const {
	Fixed	part1;
	Fixed	part2;

	part1 = (this->C.x * this->B.y) + (this->C.y * this->A.x) + (this->B.x * this->A.y);
	part2 = (this->A.x * this->B.y) + (this->A.y * C.x) + (this->B.x * this->C.y);
	return (part1 - part2);
}
