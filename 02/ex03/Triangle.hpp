#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "Fixed.hpp"
# include "./ft.hpp"

class Triangle {
	public:
		Triangle(void);
		Triangle(Triangle const & rhs);
		~Triangle(void);
		Triangle & operator=(Triangle const & rhs);

		ft::t_vector	A;
		ft::t_vector	B;
		ft::t_vector	C;

		Fixed calc_determinant(void) const;
		Fixed calc_area(void) const;
};

#endif