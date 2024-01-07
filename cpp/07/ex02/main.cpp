#include <iostream>
#include "Array.hpp"

int main(void) 
{
	try {
		Array<int> arr(3);
		arr[0] = 10;
		arr[1] = 3;
		arr[2] = 7;
		Array<int> arr2(arr);
		std::cout << arr[0] << std::endl;
		std::cout << arr[1] << std::endl;
		std::cout << arr[2] << std::endl;
		std::cout << arr[3] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
}