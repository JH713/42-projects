#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) { 
		std::cout << "Error: At least one argument is required." << std::endl;
		return 1; 
	}

	try {
		PmergeMe pmergeMe;

		for(int i = 1; i < argc; i++) {
			std::string temp(argv[i]);
			pmergeMe.addInput(temp);
		}

		pmergeMe.printResult();
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}