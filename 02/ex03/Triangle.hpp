#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "Fixed.hpp"
# include "./ft.hpp"

class Triangle {
	public:
		Triangle(void);
		~Triangle(void);
		ft::t_vector A;
		ft::t_vector B;
		ft::t_vector C;
};

#endif