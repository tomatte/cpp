#include <iostream>

template <typename T>
T max(T & a, T & b)
{
	return (a >= b ? a : b);
}

int	main(void)
{
	double a = 5;
	double	b = 8;

	std::cout << "Max: " << max<double>(a, b);
	return (0);
}