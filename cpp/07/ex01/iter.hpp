#ifndef ITER_HPP
# define ITER_HPP

# include <stdlib.h>

template <typename T>
void iter(T *arrPtr, size_t arrSize, void(*func)(T&))
{
	for (size_t i = 0; i < arrSize; ++i)
		func(arrPtr[i]);
}

#endif