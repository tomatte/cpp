#include <iostream>
#include "templates.hpp"

int	main(void)
{

	std::cout << "---------------- Subject Test -----------------" << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;


	std::string p = "pizza";
	std::string	h = "hamburger";

	swap(p, h);
	std::cout << "p: " << p << std::endl;
	std::cout << "h: " << h << std::endl;

	const int x = 20;
	const int y = 20;
	std::cout << "x pointer:   " << &x << std::endl;
	std::cout << "y pointer:   " << &y << std::endl;
	std::cout << "min pointer: " << &(min(x, y)) << std::endl;
	std::cout << "max pointer: " << &(max(x, y)) << std::endl;

	const double w = 41.9;
	const double z = 42;
	std::cout << "\n\nw:   " << w << std::endl;
	std::cout << "z:   " << z << std::endl;
	std::cout << "min: " << (min(w, z)) << std::endl;
	std::cout << "max: " << (max<double>(w, z)) << std::endl;
	return (0);
}
