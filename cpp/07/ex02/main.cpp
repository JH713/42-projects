#include "Array.hpp"
#include <cstdlib>
#include <iostream>

void leaks(void)
{
	system("leaks array");
}

int main(void)
{
	atexit(leaks);

	Array<int> arr(5);

	try
	{
		std::cout << arr[0] << std::endl;
		std::cout << arr[-1] << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}