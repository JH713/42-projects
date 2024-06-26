#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class PmergeMe{
private:
	std::deque<std::pair<int, int> > initialDeque;
	std::vector<std::pair<int, int> > initialVector;

	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &ref);

	bool isNum(std::string str);
	int strToInt(const std::string &str);
	std::deque<std::pair<int, int> > sortDeque(std::deque<std::pair<int, int> > deque);
	int binarySearch(std::deque<std::pair<int, int> > deque, int mainSize, int value);
	std::vector<std::pair<int, int> > sortVector(std::vector<std::pair<int, int> > vector);
	int binarySearch(std::vector<std::pair<int, int> > vector, int mainSize, int value);
	void printDeque(std::deque<std::pair<int, int> > deque);
	void printDequeIndex(std::deque<std::pair<int, int> > deque);
	void printVector(std::vector<std::pair<int, int> > vector);
public:
	PmergeMe();
	~PmergeMe();

	void addInput(std::string str);
	void printResult();
};

#endif