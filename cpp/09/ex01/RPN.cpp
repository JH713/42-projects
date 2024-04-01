#include "RPN.hpp"

RPN::RPN(std::string input) : input(input) {}

RPN::~RPN() {}

int RPN::calculate() {
	std::istringstream ss(input);
	std::string temp;

	while (std::getline(ss, temp, ' ')) {
		if (isDigit(temp)) {
			stack.push(strToInt(temp));
		} else if (isOperator(temp)) {
			int num1 = 0;
			int num2 = 0;
			if (!stack.empty()) {
				num2 = stack.top();
				stack.pop();
			} else
				throw std::runtime_error("Error: invalid input");

			if (!stack.empty()) {
				num1 = stack.top();
				stack.pop();
			} else
				throw std::runtime_error("Error: invalid input");

			int tempResult = cal(num1, num2, temp);
			stack.push(tempResult);
		} else
			throw std::runtime_error("Error: invalid input");
	}

	int result = 0;

	if (!stack.empty()) {
		result = stack.top();
		stack.pop();
	} else
		throw std::runtime_error("Error: invalid input");

	if (!stack.empty())
		throw std::runtime_error("Error: invalid input");

	return result;
}

int RPN::cal(int num1, int num2, std::string op) {
	long long result = 0;
	if (op == "+") {
		result = num1 + num2;
	} else if (op == "-") {
		result = num1 - num2;
	} else if (op == "*") {
		result = num1 * num2;
	} else if (op == "/") {
		if (num2 == 0) {
			throw std::runtime_error("Error: division by zero");
		}
		result = num1 / num2;
	}

	if (result < INT_MIN || result > INT_MAX)
		throw std::runtime_error("Error: overflow");

	return result;
}

int RPN::strToInt(const std::string &str) {
	std::stringstream ss(str);
	int result;
	ss >> result;
	return result;
}

bool RPN::isDigit(std::string str) {
	if (str.length() != 1) { return false; }
	return isdigit(str[0]);
}

bool RPN::isOperator(std::string str) {
	if (str.length() != 1) { return false; }
	if (str == "+" || str == "-" || str == "*" || str == "/") { return true; }
	return false;
}