#ifndef ITER_H
# define ITER_H

template<typename T, typename U>
void	iter(T *addr, U len, void (*func)(T &))
{
	for (U i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

template<typename T, typename U>
void	iter(T *addr, U len, void (*func)(T const &))
{
	for (U i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

#endif