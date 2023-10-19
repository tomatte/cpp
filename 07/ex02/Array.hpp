#ifndef ARRAY_H
# define ARRAY_H
# include <stdexcept>
# include <iostream>

template<typename T>
class Array
{
	private:
		T	*_n;
		unsigned int	_size;
	public:
		Array(void);

		Array(unsigned int n);

		Array(Array<T> const & rhs);

		~Array(void);

		unsigned int	size(void) const;

		void	set_array(T *arr, unsigned int len);

		Array<T> & operator=(Array<T> const & rhs);

		template <typename U>
		T & operator[](U index);

		template <typename U>
		T const & operator[](U index) const;
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> & arr);

# include "Array.tpp"

#endif
