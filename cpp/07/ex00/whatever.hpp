#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template <typename T>
T min(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	else
		return val2;
}

template <typename T>
T max(T val1, T val2)
{
	if (val1 > val2)
		return val1;
	else
		return val2;
}

#endif