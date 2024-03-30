#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) { 
		std::cout << "Error: Exactly one argument is required." << std::endl;
		return 1; 
	}

	std::string input(argv[1]);
	RPN rpn(input);

	try {
		std::cout << rpn.calculate() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() <<std::endl;
		return 1;
	}

	return 0;
}