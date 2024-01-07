#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>

template <class T>
class Array 
{
private:
	T* arr;
	unsigned int len;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array& operator=(const Array& ref);
	~Array();

	unsigned int size() const;

	T& operator[](unsigned int idx);
	T operator[](unsigned int idx) const;
};

template <class T>
Array<T>::Array() :arr(0), len(0) {}

template <class T>
Array<T>::Array(unsigned int n) :len(n)
{
	if ( n == 0 ) arr = 0;
	else arr = new T[n];
}

template <class T>
Array<T>::Array(const Array &copy)
{
	if (copy.len == 0) 
	{
		arr = 0;
		len = 0;
	}
	else 
	{
		arr = new T[copy.len];
		len = copy.len;
		for (int i = 0; (unsigned int) i < len; i++)
			arr[i] = copy.arr[i];
	}
}

template <class T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (arr) delete []arr;
	if (ref.len == 0) 
	{
		arr = 0;
		len = 0;
	}
	else 
	{
		arr = new T[ref.len];
		len = ref.len;
		for (int i = 0; i < len; i++)
			arr[i] = ref.arr[i];
	}
	return *this;
}

template <class T>
Array<T>::~Array()
{
	if (len > 0) delete []arr;
}

template <class T>
unsigned int Array<T>::size() const
{
	return len;
}

template <class T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= len)
		throw std::out_of_range("Array index out of bound exception");
	return arr[idx];
	
}

template <class T>
T Array<T>::operator[](unsigned int idx) const 
{
	if (idx >= len)
		throw std::out_of_range("Array index out of bound exception");
	return arr[idx];
}

#endif