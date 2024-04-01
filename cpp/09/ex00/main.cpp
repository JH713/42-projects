#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "utils.hpp"

struct InputData;

void processInput(std::ifstream &input);
InputData parseInputLine(std::string line);

int main(int argc, char *argv[]) {
	if (argc !=  2) {
		std::cout << "Error: Exactly one input file is required." << std::endl;
		std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	std::ifstream input;
	input.open(argv[1]);
	if (!input) {
		std::cout << "Error: Failed to open input file." << std::endl;
		return 1;
	}

	processInput(input);

	input.close();

	return 0;
}

struct InputData {
	std::string dateString;
	int time;
	double value;
};

void processInput(std::ifstream &input) {
	std::string line;
	std::getline(input, line); // 첫 번째 줄은 통과
	BitcoinExchange exchange;
	while (std::getline(input, line)) {
		try {
			InputData data = parseInputLine(line);
			double result = exchange.exchange(data.time, data.value);
			std::cout << data.dateString << " => " << data.value << " = " << result << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() <<std::endl;
		}
	}
}

InputData parseInputLine(std::string line) {
	if (line.length() < 14) 
		throw std::runtime_error("Error: bad input => " + line);
	
	std::string date = line.substr(0, 10);
	std::string separator = line.substr(10, 3);
	std::string value = line.substr(13);

	if (separator.compare(" | ") != 0)
		throw std::runtime_error("Error: bad input => " + line);

	int time = changeDateToTime(date);
	if (time < 0)
		throw std::runtime_error("Error: bad input => " + line);
	
	if (!isDouble(value))
		throw std::runtime_error("Error: bad input => " + line);
	if (value[0] == '-')
		throw std::runtime_error("Error: not a positive number.");

	double val = strToNum<double>(value);
	if (val < 0 || val > 1000)
		throw std::runtime_error("Error: Value " + value + " is not between 0 and 1000.");
	
	InputData result;
	result.dateString = date;
	result.time = time;
	result.value = val;

	return result;
}