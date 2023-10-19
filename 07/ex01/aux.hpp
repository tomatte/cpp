#ifndef AUX_H
# define AUX_H
# include <iostream>

template<typename T>
void	print_content(T & content)
{
	std::cout << content;
}

template <typename T>
void	print_times2(T & x)
{
	std::cout << x << " * 2 == " << x * 2 << std::endl;
}

#endif