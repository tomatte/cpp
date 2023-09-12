/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:09:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/12 07:42:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : fixed(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n) : fixed(n << this->fractionalBits) {
	std::cout << "Parameter constructor called\n";
}

Fixed::Fixed(float const n) {
	int const FIXED_POINT = (1 << this->fractionalBits);

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

int const Fixed::fractionalBits = 8;

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

	for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
		if (((1 << i) & this->fixed) != 0) { //verify if bit is 1
			expoent = (i - this->fractionalBits);
			if (expoent > 0)
				number += std::pow(2, expoent);
			else
				number += 1 / std::pow(2, std::abs(expoent)); //this is the same as 2^-i, but in this case is (1 / 2)^i
		}
	}
	return (number);
}

int	Fixed::toInt(void) const {
	return (this->fixed >> this->fractionalBits);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}
