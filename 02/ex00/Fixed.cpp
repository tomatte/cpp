#include "Fixed.hpp"
#include <iostream>

int const Fixed::fractionalBits = 8;

Fixed::Fixed(void) : fixed(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const & rhs) {
	std::cout << "Copy constructor called\n";
	*this = rhs;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called\n";
	this->fixed = rhs.getRawBits();
	return (*this);
}

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
