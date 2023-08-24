#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& copy) { (void) copy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) { (void) ref; return (*this); }
ScalarConverter::~ScalarConverter() {}

static void convertChar(std::string str)
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

static bool isInt(std::string str)
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

static void print_impossible(void)
{
	std::cout << "char: impossible" << std::endl; 
	std::cout << "int: impossible" << std::endl; 
	std::cout << "float: impossible" << std::endl; 
	std::cout << "double: impossible" << std::endl;
}

static void convertInt(std::string str)
{
	int frontZero = 0;
	if (str[0] == '-')
		++frontZero; 
	while (str[frontZero] == '0')
		++frontZero;
	if (static_cast<int>(str.length()) > 11 + frontZero)
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
	if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl; 
	else if (isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl; 
	else
		std::cout << "char: Non displayable" << std::endl; 
	std::cout << "int: " << num << std::endl; 
	std::cout<<std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl; 
	std::cout << "double: " << static_cast<double>(num) << std::endl; 
}

static bool isDouble(std::string str)
{
	if (str.empty())
		return false;
	std::string pseudoLiterals[4] = {"inf", "+inf", "-inf", "nan"};
	for (int i = 0; i < 4; ++i)
	{
		if (str == pseudoLiterals[i])
			return true;
	}
	size_t idx = str.find('.');
	if (idx == std::string::npos || idx == 0 || idx == str.length() - 1)
		return false;
	for (int i = 0; i < static_cast<int>(idx); ++i)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
		{
			if (str[i + 1] == '.')
				return false;
			continue;
		}
		if (!isdigit(str[i]))
			return false;
	}
	for (int i = idx + 1; i < static_cast<int>(str.length()); ++i)
		if (!isdigit(str[i]))
			return false;
	return true;
}

static bool isFloat(std::string str)
{
	if (str[str.length() - 1] != 'f')
		return false;
	str.resize(str.length() - 1);
	if (isDouble(str))
		return true;
	return false;
}

static void convertFloat(std::string str)
{
	str.resize(str.length() - 1);
	std::string pseudoLiterals[4] = {"inf", "+inf", "-inf", "nan"};
	for (int i = 0; i < 4; ++i)
	{
		if (str == pseudoLiterals[i])
		{
			if (i == 1)
				str = str.substr(1);
			std::cout << "char: impossible" << std::endl; 
			std::cout << "int: impossible" << std::endl; 
			std::cout << "float: " << str << 'f' << std::endl; 
			std::cout << "double: " << str << std::endl;
			return ;
		}
	}
	try 
	{
		float num = stof(str);
		if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
			std::cout << "char: impossible" << std::endl; 
		else if (isprint(num))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl; 
		else
			std::cout << "char: Non displayable" << std::endl; 
		if (static_cast<double>(num) > std::numeric_limits<int>::max() || static_cast<double>(num) < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl; 
		else
			std::cout << "int: " << static_cast<int>(num) << std::endl; 
		std::cout<<std::fixed;
		std::cout.precision(1);
		std::cout << "float: " << num << "f" << std::endl; 
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	catch (std::out_of_range& e) 
	{
		print_impossible();
	}
}

static void convertDouble(std::string str)
{
	std::string pseudoLiterals[4] = {"inf", "+inf", "-inf", "nan"};
	for (int i = 0; i < 4; ++i)
	{
		if (str == pseudoLiterals[i])
		{
			if (i == 1)
				str = str.substr(1);
			std::cout << "char: impossible" << std::endl; 
			std::cout << "int: impossible" << std::endl; 
			std::cout << "float: " << str << 'f' << std::endl; 
			std::cout << "double: " << str << std::endl;
			return ;
		}
	}
	try 
	{
		double num = stod(str);
		if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
			std::cout << "char: impossible" << std::endl; 
		else if (isprint(num))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl; 
		else
			std::cout << "char: Non displayable" << std::endl; 
		if (static_cast<double>(num) > std::numeric_limits<int>::max() || static_cast<double>(num) < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl; 
		else
			std::cout << "int: " << static_cast<int>(num) << std::endl; 
		std::cout<<std::fixed;
		std::cout.precision(1);
		if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
			std::cout << "float: impossible" << std::endl; 
		else
			std::cout << "float: " << static_cast<float>(num) << "f" << std::endl; 
		std::cout << "double: " << num << std::endl;
	}
	catch (std::out_of_range& e) 
	{
		print_impossible();
	}
}

void ScalarConverter::convert(std::string str)
{
	if (str.empty())
		std::cout << "Invalid input" << std::endl;
	else if (str.length() == 1 && !isdigit(str[0]))
		convertChar(str);
	else if (isInt(str))
		convertInt(str);
	else if (isFloat(str))
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else
		std::cout << "Invalid input" << std::endl;
}  