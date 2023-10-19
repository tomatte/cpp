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

#endif