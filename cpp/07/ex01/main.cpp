#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T element)
{
	std::cout << element << std::endl;
}

void addOne(int& num)
{
	num += 1;
}

int main(void)
{
	int arr1[4] = {10, 20, 30, 40};
	std::string arr2[3] = {"abc", "xyz", "pqr"};

	::iter(arr1, 4, addOne);
	::iter(arr1, 4, printElement);
	::iter(arr2, 3, printElement);
}