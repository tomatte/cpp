/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:44:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/26 10:04:54 by dbrandao         ###   ########.fr       */
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
	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";
	std::cout << "c is " << c << "\n";
	std::cout << "d is " << d << "\n";

	std::cout << "\n---------- TEST 2 ----------\n";
	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	std::cout << "b is " << b.toInt() << " as integer" << "\n";
	std::cout << "c is " << c.toInt() << " as integer" << "\n";
	std::cout << "d is " << d.toInt() << " as integer" << "\n";

	std::cout << "\n---------- TEST 3 ----------\n";
	std::cout << "b: " << b << " | c: " << c << "\n";
	std::cout << "b < c: " << (b < c) << "\n";
	std::cout << "b > c: " << (b > c) << "\n";
	std::cout << "b == c: " << (b == c) << "\n";
	std::cout << "b != c: " << (b != c) << "\n";

	std::cout << "\n---------- TEST 4 ----------\n";
	std::cout << "b: " << b << " | c: " << c << "\n";
	std::cout << "b + c: " << (b + c) << "\n";
	std::cout << "b - c: " << (b - c) << "\n\n";
	Fixed n3((float) -5.1);
	Fixed n4((float) -10.1);
	std::cout << "n3 = " << n3 << " | n4 = " << n4 << "\n";
	std::cout << "n3 + n4: " << n3 + n4 << "\n";
	std::cout << "n3 * n4: " << n3 * n4 << "\n";

	std::cout << "\n---------- TEST 5 ----------\n";
	Fixed n5 = -1;
	std::cout << "n5: " << n5 << "\n";
	std::cout << "++n5: " << (++n5) << "\n";
	n5 = 1;
	std::cout << "n5: " << n5 << "\n";
	std::cout << "++n5: " << (++n5) << "\n\n";

	Fixed n6 = -1;
	std::cout << "n6: " << n6 << "\n";
	std::cout << "n6++: " << (n6++) << "\n";
	std::cout << "n6: " << n6 << "\n\n";
	n6 = 1;
	std::cout << "n6: " << n6 << "\n";
	std::cout << "n6++: " << n6++ << "\n";
	std::cout << "n6: " << n6 << "\n";

	std::cout << "\n---------- TEST 6 ----------\n";
	Fixed n7 = -1;
	std::cout << "n7: " << n7 << "\n";
	std::cout << "--n7: " << (--n7) << "\n";
	n7 = 1;
	std::cout << "n7: " << n7 << "\n";
	std::cout << "--n7: " << (--n7) << "\n\n";

	Fixed n8 = -1;
	std::cout << "n8: " << n8 << "\n";
	std::cout << "n8--: " << (n8--) << "\n";
	std::cout << "n8: " << n8 << "\n\n";

	n8 = 1;
	std::cout << "n8: " << n8 << "\n";
	std::cout << "n8--: " << n8-- << "\n";
	std::cout << "n8: " << n8 << "\n";

	std::cout << "\n---------- TEST 7 ----------\n";
	Fixed	n10(3.14f);
	Fixed	n9(3.0f);
	std::cout << "n9: " << n9 << " | n10: " << n10 << "\n";
	std::cout << "max(n10, n9): " << Fixed::max(n10, n9) << "\n";
	std::cout << "min(n10, n9): " << Fixed::min(n10, n9) << "\n\n";

	std::cout << "const b: " << b << " | const c: " << c << "\n";
	std::cout << "max(b, c): " << Fixed::max(b, c) << "\n";
	std::cout << "min(b, c): " << Fixed::min(b, c) << "\n";
	return (0);
}
