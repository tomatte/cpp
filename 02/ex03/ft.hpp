#ifndef FT_H
# define FT_H
# include "Fixed.hpp"

namespace ft {
	int	pow(int num, int power);

	float	abs(float number);

	typedef struct s_vector {
		Fixed	x;
		Fixed	y;
	}	t_vector;
}

#endif