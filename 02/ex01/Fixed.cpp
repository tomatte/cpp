/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:09:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/26 08:42:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "ft.hpp"

int const Fixed::fractionalBits = 8;

Fixed::Fixed(void) : fixed(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n) : fixed(n << Fixed::fractionalBits) {
	std::cout << "Int constructor called\n";
}
Fixed::Fixed(float const n) {
	int const FIXED_POINT = (1 << Fixed::fractionalBits);

	this->fixed = n * FIXED_POINT;
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(Fixed const & rhs) {
	std::cout << "Copy constructor called\n";
	*this = rhs;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called\n";
	this->fixed = rhs.fixed;
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed = raw;
}

float	Fixed::toFloat(void) const {
	float	number;

	number = (float) this->fixed / (float)(1 << Fixed::fractionalBits);
	return (number);
}

int	Fixed::toInt(void) const {
	return (this->fixed >> Fixed::fractionalBits);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}
