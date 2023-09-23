/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/21 16:28:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>
#include "ft.hpp"

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
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "---------- TEST 1 ----------\n";
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\n---------- TEST 2 ----------\n";
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "\n---------- TEST 3 ----------\n";
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << "\n---------- TEST 4 ----------\n";
	std::cout << "b + c: " << (b + c) << std::endl;
	std::cout << "b - c: " << (b - c) << std::endl;
	std::cout << "test: " << Fixed((float) -1.5) << std::endl;
	Fixed n1(-5);
	std::cout << "n1: " << n1 << std::endl;
	Fixed n2(0);
	std::cout << "n2: " << n2 << std::endl;
	Fixed n3((float) -5.1);
	Fixed n4((float) -10.1);
	std::cout << "n3 + n4: " << n3 + n4 << std::endl;

	return (0);
}