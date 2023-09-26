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
		Fixed	operator/(Fixed const & rhs) const;
		
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed & lhs, Fixed & rhs);
		static Fixed const &	min(Fixed const & lhs, Fixed const & rhs);
		static Fixed &			max(Fixed & lhs, Fixed & rhs);
		static Fixed const &	max(Fixed const & lhs, Fixed const & rhs);
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif