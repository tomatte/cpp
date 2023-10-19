#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _n(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(new T[n]), _size(n)
{
	for (unsigned int i = 0; i < n; i++)
	this->_n[i] = T();
}

template <typename T>
Array<T>::Array(Array<T> const & rhs) : _n(new T[rhs.size()]), _size(rhs.size())
{
	for (unsigned int i = 0; i < this->_size; i++)
		(*this)[i] = rhs[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_n;
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
void	Array<T>::set_array(T *arr, unsigned int len)
{
	delete [] this->_n;
	this->_n = new T[len];
	this->_size = len;
	for (unsigned int i = 0; i < len; i++)
		(*this)[i] = arr[i];
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs)
{
	delete [] this->_n;
	this->_size = rhs.size();
	this->_n = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_n[i] = T(rhs[i]);
	return (*this);
}

template <typename T>
template <typename U>
T const & Array<T>::operator[](U index) const
{
	if (static_cast<unsigned int>(index) >= this->_size)
		throw std::exception();
	return (this->_n[index]);
}

template <typename T>
template <typename U>
T & Array<T>::operator[](U index)
{
	if (static_cast<unsigned int>(index) >= this->_size)
		throw std::exception();
	return (this->_n[index]);
}

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> & arr)
{
	unsigned int	i;

	o << '[';
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