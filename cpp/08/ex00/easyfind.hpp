#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <class T>
typename T::iterator easyfind(T& container, int val)
{
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	return std::find(begin, end, val);
}

#endif