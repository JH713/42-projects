#include <iostream>
#include "iter.hpp"

void printInt(const int& a)
{
	std::cout << a << std::endl;
}

template <class T>
void increment(T& a)
{
	a = a + 1;
}


int main(void) 
{
	int arr[3] = {1, 2, 3};

	iter<int>(arr, 3, printInt);
	iter<int>(arr, 3, increment<int>);
	iter<int>(arr, 3, printInt);
}