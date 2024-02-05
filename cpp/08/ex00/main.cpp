#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::vector<int>::iterator iter = easyfind<std::vector<int> >(v, 3);
	std::cout << "인덱스: " << iter - v.begin() << std::endl;
	std::cout << "값: " << *iter << std::endl;

}