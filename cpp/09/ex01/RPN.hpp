#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <iostream> 

class RPN {
private:
	std::string input;
	std::stack<int> stack;

	RPN(const RPN &copy);
	RPN &operator=(const RPN &ref);

	int cal(int num1, int num2, std::string op);
	int strToInt(const std::string &str);
	bool isDigit(std::string str);
	bool isOperator(std::string str);
public:
	RPN(std::string input);
	~RPN();

	int calculate();
};

#endif 