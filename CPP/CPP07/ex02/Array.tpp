
#include <iostream>

template <typename T>
Array<T>::Array( void )
{
	arr = NULL;
	len = 0;
}

template <typename T>
Array<T>::Array( unsigned int n )
{
	len = n;
	arr = new T[n];
}

template <typename T>
Array<T>::Array( const Array &other )
{
	len = other.len;

	arr = new T[other.len];
	
	for (unsigned int i = 0; i < len; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=( const Array &other )
{
	if (this != &other)
	{
		if (this->arr)
			delete[] arr;

		len = other.len;
		arr = new T[other.len];

		for (unsigned int i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
	return (len);
}

template <typename T>
Array<T>::~Array( void )
{
	delete[] arr;
}

template <typename T>
T &Array<T>::operator[] (int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= len)
		throw std::exception();
	return (arr[index]);
}

template <typename T>
const T &Array<T>::operator[] (int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= len)
		throw std::exception();
	return (arr[index]);
}
