/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/24 07:14:41 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "ft.hpp"

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
	std::cout << "n3 * n4: " << n3 * n4 << std::endl;

	std::cout << "\n---------- TEST 5 ----------\n";
	Fixed n5 = -1;
	std::cout << "++n5: " << (++n5) << std::endl;
	n5 = 1;
	std::cout << "++n5: " << (++n5) << std::endl;

	Fixed n6 = -1;
	std::cout << "n6++: " << (n6++) << std::endl;
	n6 = 1;
	std::cout << "(n6++): " << (n6++) << std::endl;
	std::cout << "n6++: " << n6++ << " | then: " << n6 << std::endl;

	std::cout << "\n---------- TEST 6 ----------\n";
	Fixed n7 = -1;
	std::cout << "--n7: " << (--n7) << std::endl;
	n7 = 1;
	std::cout << "--n7: " << (--n7) << std::endl;

	Fixed n8 = -1;
	std::cout << "n8--: " << (n8--) << std::endl;
	n8 = 1;
	std::cout << "(n8--): " << (n8--) << std::endl;
	std::cout << "n8--: " << n8-- << " | then: " << n8 << std::endl;

	std::cout << "\n---------- TEST 7 ----------\n";
	Fixed	n10(3.14f);
	Fixed	n9(3.0f);
	std::cout << "max(n10, n9): " << Fixed::max(n10, n9) << std::endl;
	std::cout << "max(n10, n9): " << Fixed::min(n10, n9) << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
	std::cout << "max(b, c): " << Fixed::min(b, c) << std::endl;
	return (0);
}
