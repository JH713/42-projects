#ifndef UTILS_HPP
# define UTILS_HPP

#include <sstream>
#include <string>
#include <iostream>

int changeDateToTime(std::string date);
bool isDouble(std::string str);

template<typename T>
T strToNum(const std::string &str) {
	std::stringstream ss(str);
	T result;
	ss >> result;
	return result;
}

#endif 