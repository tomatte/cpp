#ifndef ITER_H
# define ITER_H

template<typename T, typename U, typename F>
void	iter(T *addr, U len, F func)
{
	for (U i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

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