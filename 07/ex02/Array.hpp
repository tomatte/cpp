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
		Array(void) : _n(new T[0]), _size(0) {}

		Array(unsigned int n) : _n(new T[n]), _size(n) {
			for (unsigned int i = 0; i < n; i++)
				this->_n[i] = T();
		}

		Array(Array & rhs) : _n(new T[rhs.size()]), _size(rhs.size()) {
			for (unsigned int i = 0; i < this->_size; i++)
				(*this)[i] = rhs[i];
		}

		~Array(void) { delete [] this->_n; }

		unsigned int	size(void) const {
			return (this->_size);
		}

		void	set_array(T *arr, unsigned int len)
		{
			delete [] this->_n;
			this->_n = new T[len];
			this->_size = len;
			for (unsigned int i = 0; i < len; i++)
				(*this)[i] = arr[i];
		}

		template <typename U>
		Array<T> & operator=(Array<T> const & rhs) {
			delete [] this->_n;
			this->_size = rhs.size();
			for (unsigned int i = 0; i < this->_size; i++)
				(*this)[i] = rhs[i];
			return (*this);
		}

		template <typename U>
		T & operator[](U index) {
			if (static_cast<unsigned int>(index) >= this->_size)
				throw std::exception();
			return (this->_n[index]);
		}
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> & arr)
{
	o << '[';
	unsigned int	i;
	if (arr.size() == 0)
	{
		o << ']';
		return (o);
	}
	for (i = 0; i < arr.size() - 1; i++)
		o << arr[i] << ", ";
	o << arr[i] << "]";
	return (o);
}

#endif
