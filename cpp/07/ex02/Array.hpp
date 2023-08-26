#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int length;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	Array& operator=(const Array& ref);
	~Array();

	T& operator[] (unsigned int n);
	T operator[] (unsigned int n) const;
	unsigned int size() const;
};

template <typename T>
Array<T>::Array()
{ this->arr = 0; this->length = 0; }

template <typename T>
Array<T>::Array(unsigned int n)
{ 
	this->arr = new T[n]; 
	for (unsigned int i = 0; i < n; i++)
		this->arr[i] = 0;
	this->length = n;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	if (copy.length == 0)
	{
		this->arr = 0; 
		this->length = 0;
		return ;
	}
	this->arr = new T[copy.length];
	for (int i = 0; i < copy.length; i++)
		this->arr[i] = copy.arr[i];
	this->length= copy.length;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (this->length != 0)
		delete []this->arr;
	if (ref.length == 0)
	{
		this->arr = 0; 
		this->length = 0;
		return ;
	}
	this->arr = new T[ref.length];
	for (int i = 0; i < ref.length; i++)
		this->arr[i] = ref.arr[i];
	this->length = ref.length;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->length != 0)
		delete []this->arr;
}

template <typename T>
T& Array<T>::operator[] (unsigned int n)
{
	if (n < 0 || n > this->length)
		throw std::out_of_range("Array index out of bound exception");
	return this->arr[n];
}

template <typename T>
T  Array<T>::operator[] (unsigned int n) const
{
	if (n < 0 || n > this->length)
		throw std::out_of_range("Array index out of bound exception");
	return this->arr[n];
}

template <typename T>
unsigned int Array<T>::size() const
{ return this->length; }

#endif