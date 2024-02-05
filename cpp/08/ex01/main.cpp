#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(27);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp = Span(10000);
		srand(time(0));
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(rand());
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp(10);
		std::vector<int> nums;
		for (int i = 0; i < 5; i++) {
			nums.push_back(i);
		}

		sp.addNumbers(nums.begin(), nums.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

return 0;
}