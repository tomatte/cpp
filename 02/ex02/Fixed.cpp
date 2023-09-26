/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:09:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/26 09:55:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "ft.hpp"

int const Fixed::fractionalBits = 8;

Fixed::Fixed(void) : fixed(0) {
}

Fixed::Fixed(int const n) : fixed(n << Fixed::fractionalBits) {
}

Fixed::Fixed(float const n) {
	int const FIXED_POINT = (1 << Fixed::fractionalBits);

	this->fixed = n * FIXED_POINT;
}

Fixed::Fixed(Fixed const & rhs) : fixed(rhs.fixed) {
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	this->fixed = rhs.fixed;
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

int		Fixed::getRawBits(void) const {
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed = raw;
}

float	Fixed::toFloat(void) const {
	float	number = 0;

	number = (float) this->fixed / (float)(1 << Fixed::fractionalBits);
	return (number);
}

int	Fixed::toInt(void) const {
	return (this->fixed >> Fixed::fractionalBits);
}

Fixed::~Fixed(void) {
}

bool	Fixed::operator<(Fixed const & rhs) const {
	return (this->fixed < rhs.fixed);
}

bool	Fixed::operator>(Fixed const & rhs) const {
	return (this->fixed > rhs.fixed);
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return (this->fixed <= rhs.fixed);
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return (this->fixed >= rhs.fixed);
}

bool	Fixed::operator==(Fixed const & rhs) const {
	return (this->fixed == rhs.fixed);
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return (this->fixed != rhs.fixed);
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &	Fixed::operator++(void) {
	++(this->fixed);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	float	post;

	post = this->toFloat();
	this->fixed++;
	return (Fixed(post));
}

Fixed &	Fixed::operator--(void) {
	--(this->fixed);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	float	post;

	post = this->toFloat();
	this->fixed--;
	return (Fixed(post));
}

Fixed &	Fixed::min(Fixed & lhs, Fixed & rhs) {
	if (rhs.toFloat() < lhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

Fixed const &	Fixed::min(Fixed const & lhs, Fixed const & rhs) {
	if (rhs.toFloat() < lhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

Fixed &	Fixed::max(Fixed & lhs, Fixed & rhs) {
	if (rhs.toFloat() > lhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

Fixed const &	Fixed::max(Fixed const & lhs, Fixed const & rhs) {
	if (rhs.toFloat() > lhs.toFloat())
		return (rhs);
	else
		return (lhs);
}
