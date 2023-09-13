/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:09:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/13 17:04:44 by dbrandao         ###   ########.fr       */
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
	std::cout << "Parameter constructor called\n";
}
Fixed::Fixed(float const n) {
	int const FIXED_POINT = (1 << Fixed::fractionalBits);

	this->fixed = n * FIXED_POINT;
	std::cout << "Parameter constructor called\n";
}

Fixed::Fixed(Fixed const & rhs) : fixed(rhs.fixed) {
	std::cout << "Copy constructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	this->fixed = rhs.fixed;
	std::cout << "Copy assignment operator called\n";
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
	int		expoent;
	float	number = 0;

	for (int i = sizeof(int) * Fixed::fractionalBits - 1; i >= 0; i--) {
		if (((1 << i) & this->fixed) != 0) {
			expoent = (i - Fixed::fractionalBits);
			if (expoent > 0)
				number += ft::pow(2, expoent);
			else
				number += 1 / (float) ft::pow(2, ft::abs(expoent));
		}
	}
	return (number);
}

int	Fixed::toInt(void) const {
	return (this->fixed >> Fixed::fractionalBits);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}
