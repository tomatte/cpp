#ifndef FT_H
# define FT_H
# include "Fixed.hpp"

namespace ft {
	int	pow(int num, int power);

	int	abs(int number);

	typedef struct s_vector {
		Fixed	x;
		Fixed	y;
	}	t_vector;
}

#endif