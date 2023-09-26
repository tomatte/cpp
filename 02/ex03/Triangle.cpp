#include "Triangle.hpp"

Triangle::Triangle(void) {
}

Triangle::Triangle(
		float ax, float ay,
		float bx, float by,
		float cx, float cy
	) {
	this->A.x = ax;
	this->A.y = ay;
	this->B.x = bx;
	this->B.y = by;
	this->C.x = cx;
	this->C.y = cy;
}

Triangle::Triangle(Triangle const & rhs) : A(rhs.A), B(rhs.B), C(rhs.C) {
}

Triangle::~Triangle(void) {
}

Triangle & Triangle::operator=(Triangle const & rhs) {
	this->A = rhs.A;
	this->B = rhs.B;
	this->C = rhs.C;
	return (*this);
}

Fixed Triangle::calc_determinant(void) const {
	Fixed	part1;
	Fixed	part2;

	part1 = (this->C.x * this->B.y) + (this->C.y * this->A.x) + (this->B.x * this->A.y);
	part2 = (this->A.x * this->B.y) + (this->A.y * C.x) + (this->B.x * this->C.y);
	return (part1 - part2);
}

Fixed Triangle::calc_area(void) const {
	Fixed	area;
	float	determinant;

	determinant = this->calc_determinant().toFloat();
	area = 0.5f * ft::abs(determinant);
	return (area);
}
