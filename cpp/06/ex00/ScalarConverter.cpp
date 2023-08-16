#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& copy) { (void) copy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) { (void) ref; return (*this); }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str)
{
	std::cout << str << std::endl;
}