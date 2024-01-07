#ifndef ITER_HPP
# define ITER_HPP

template <class T>
void iter(T* arr, size_t len, void (*func)(T&))
{
	for (int i = 0; (size_t) i < len; i++) 
	{
		func(arr[i]);
	}
}

template <class T>
void iter(const T* arr, size_t len, void (*func)(const T&))
{
	for (int i = 0; (size_t) i < len; i++) 
	{
		func(arr[i]);
	}
}

#endif