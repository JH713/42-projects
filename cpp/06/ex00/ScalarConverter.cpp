#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& copy) { (void) copy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) { (void) ref; return (*this); }
ScalarConverter::~ScalarConverter() {}

void convertChar(std::string str)
{
	std::stringstream ss;
	ss << str;
	char ch;
	ss >> ch;
	std::cout << "char: '" << ch << "'" << std::endl; 
	std::cout << "int: " << static_cast<int>(ch) << std::endl; 
	std::cout<<std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(ch) << "f" << std::endl; 
	std::cout << "double: " << static_cast<double>(ch) << std::endl; 
}

bool isInt(std::string str)
{
	for (int i = 0; i < static_cast<int>(str.length()); ++i)
	{
		if (i == 0 && (str[0] == '+' || str[0] == '-' ))
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void print_impossible(void)
{
	std::cout << "char: impossible" << std::endl; 
	std::cout << "int: impossible" << std::endl; 
	std::cout << "float: impossible" << std::endl; 
	std::cout << "double: impossible" << std::endl;
}

void convertInt(std::string str)
{
	if (str.length() > 11) // 앞에서 시작하는 000들을 제외해야함 
	{
		print_impossible();
		return ;
	}
	std::stringstream ss;
	ss << str;
	long long temp;
	ss >> temp;
	if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
	{
		print_impossible();
		return ;
	}
	int num = static_cast<int>(temp);
	if (isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl; 
	else
		std::cout << "char: Non displayable" << std::endl; 
	std::cout << "int: " << num << std::endl; 
	std::cout<<std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl; 
	std::cout << "double: " << static_cast<double>(num) << std::endl; 
}

bool isDouble(std::string str)
{
	if (str.empty())
		return false;
	size_t idx = str.find('.');
	if (idx == std::string::npos || idx == str.length() - 1)
		return false;
	for (int i = 0; i < static_cast<int>(idx); ++i)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	for (int i = idx + 1; i < static_cast<int>(str.length()); ++i)
		if (!isdigit(str[i]))
			return false;
	return true;
}

bool isFloat(std::string str)
{
	if (str[str.length() - 1] != 'f')
		return false;
	str.resize(str.length() - 1);
	if (isDouble(str))
		return true;
	return false;
}

void convertFloat(std::string str)
{
	(void)str;
	std::cout << "float\n";
}


void convertDouble(std::string str)
{
	(void)str;
	std::cout << "double\n";
}

void ScalarConverter::convert(std::string str)
{
	if (str.empty())
		print_impossible();
	else if (str.length() == 1 && !isdigit(str[0]))
		convertChar(str);
	else if (isInt(str))
		convertInt(str);
	else if (isFloat(str))
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else
		return ;
}  