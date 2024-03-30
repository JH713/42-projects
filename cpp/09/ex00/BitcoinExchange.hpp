#ifndef BITCOINTEXCHANGE_HPP
# define BITCOINTEXCHANGE_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "utils.hpp"

class BitcoinExchange {
private:
	std::map<int, double> exchangeRate; // date(날짜), exchange_rate

	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &ref);

	void getDataFromDatabase();
	void processLineFromDatabase(std::string &line);
public:
	BitcoinExchange();
	~BitcoinExchange();

	double exchange(int time, double value);

	class DatabaseFailException : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif 

