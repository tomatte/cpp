/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/12 07:41:49 by dbrandao         ###   ########.fr       */
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
		if (((1 << i) & fint) != 0) { //verify if bit is 1
			expoent = (i - NUM_FRAC_BITS);
			if (expoent > 0)
				number += std::pow(2, expoent);
			else
				number += 1 / std::pow(2, std::abs(expoent)); //this is the same as 2^-i, but in this case is (1 / 2)^i
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
	std::cout << "float: " << number << "\n";
	
	//print_bits(fint);
}



int	main(void) {

	Fixed	a(5);
	Fixed	b(1.29f);

	std::cout << "a: " << a.toInt() << "\n";
	std::cout << "a: " << a.toFloat() << "\n";
	std::cout << "b: " << b.toInt() << "\n";
	std::cout << "b: " << b.toFloat() << "\n";
/* 	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl; */
	return (0);
}