#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &copy);
	ScalarConverter& operator=(const ScalarConverter &ref);
	~ScalarConverter();
public:
	static void convert(std::string str);
};

#endif