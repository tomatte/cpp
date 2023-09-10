#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H

class Fixed {
	private:
		static int const	fractionalBits;
		int	fixed_point;
		

	public:
		Fixed(void);
		Fixed(int const fixed_point);
		Fixed(float const fixed_point);
		Fixed(Fixed const & rhs);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif