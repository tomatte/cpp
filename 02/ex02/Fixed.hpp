#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H
# include <iostream>

class Fixed {
	private:
		static int const	fractionalBits;
		int					fixed;

	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed const & rhs);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);
		bool	operator<(Fixed const & rhs) const;
		bool	operator>(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif