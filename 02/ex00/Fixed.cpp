#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : fixed(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const & rhs) : fixed(rhs.fixed) {
	std::cout << "Copy constructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	this->fixed = rhs.fixed;
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

int const Fixed::fractionalBits = 8;

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return this->fixed;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed = raw;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}
