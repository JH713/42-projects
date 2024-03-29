#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	getDataFromDatabase();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::getDataFromDatabase() {
	std::ifstream database;
	database.open("data.csv");
	if (!database)
		throw DatabaseFailException();

	std::string line;
	std::getline(database, line); // 첫 번째 줄은 통과 
	while (std::getline(database, line)) {
		processLineFromDatabase(line);
	}

	database.close();
}

void BitcoinExchange::processLineFromDatabase(std::string &line) {
	std::istringstream ss(line);
	std::string date;
	std::string rate;

	std::getline(ss, date, ',');
	std::getline(ss, rate);

	if (date.empty() || rate.empty() ) { return; }

	int time = changeDateToTime(date);
	if (time < 0) { return; }

	if (!isDouble(rate) || rate[0] == '-') { return; }
	double val = strToNum<double>(rate);

	exchangeRate[time] = val;
}


const char*BitcoinExchange::DatabaseFailException::what() const throw() {
	return "Error: Failed to open database.";
}