/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/11 09:30:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

void	print_bits(int n) {
	for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
		if ((n & (1 << i) ) != 0)
			std::cout << "1";
		else
			std::cout << "0";
	}
	std::cout << "\n";
}

# define NUM_FRAC_BITS 8
# define FIXED_POINT (1 << NUM_FRAC_BITS)

float	toFloat(int fint) {
	int	expoent;
	float	number = 0;

	for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
		if (((1 << i) & fint) != 0) {
			expoent = (i - NUM_FRAC_BITS);
			if (expoent > 0)
				number += std::pow(2, expoent);
			else
				number += 1 / std::pow(2, std::abs(expoent));
		}
	}
	return number;
}
/*(i - NUM_FRAC_BITS)
	HOW TO REPRESENT NUMBERS

	2^-¹ == (1/2)¹ == 1¹ / 2¹

	2^-³ == (1/2)³ == 1³ / 2³
 */

void	test(float n) {
	int	fint = n * FIXED_POINT; //convert the float to fixed point number
	float number = toFloat(fint);
	std::cout << "float number: " << number << "\n";
	//print_bits(fint);
}



int	main(void) {

	test(0.2);
	test(2.3);
	test(20023.255);
	test(10.1284);
/* 	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl; */
	return (0);
}