#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : fixed_point(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const & rhs) : fixed_point(rhs.fixed_point) {
	std::cout << "Copy constructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	this->fixed_point = rhs.fixed_point;
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

int const Fixed::fractionalBits = 8;

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return this->fixed_point;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed_point = raw;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}
