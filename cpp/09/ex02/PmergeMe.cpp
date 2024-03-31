#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::addInput(std::string str) {
	if (isNum(str)) {
		int num = strToInt(str);
		initialDeque.push_back(std::make_pair(num, 0));
		initialVector.push_back(std::make_pair(num, 0));
	} else 
		throw std::runtime_error("Error");
}

bool PmergeMe::isNum(std::string str) {
	if (str.empty()) { return false; }
	for (int i = 0; i < static_cast<int>(str.length()); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

int PmergeMe::strToInt(const std::string &str) {
	if (str.length() > 10)
		throw std::runtime_error("Error");

	std::stringstream ss(str);
	long long result;
	ss >> result;

	if (result > INT_MAX || result <= 0)
		throw std::runtime_error("Error");

	return static_cast<int>(result);
}

void PmergeMe::printDeque(std::deque<std::pair<int, int> > deque) {
	std::deque<std::pair<int, int> >::iterator iter;
	for (iter = deque.begin(); iter != deque.end(); iter++) {
		std::cout << (*iter).first << " ";
	}

	std::cout << std::endl;
}

void PmergeMe::printDequeIndex(std::deque<std::pair<int, int> > deque) {
	std::deque<std::pair<int, int> >::iterator iter;
	for (iter = deque.begin(); iter != deque.end(); iter++) {
		std::cout << (*iter).second << " ";
	}

	std::cout << std::endl;
}

void PmergeMe::printResult() {
	std::cout << "Before: ";
	printDeque(initialDeque);
	
	std::deque<std::pair<int, int> > sortedDeque = sortDeque(initialDeque);
	std::cout << "After: ";
	std::deque<std::pair<int, int> >::iterator iter;
	for (iter = sortedDeque.begin(); iter != sortedDeque.end(); iter++) {
		std::cout << (*iter).first << " ";
	}
	std::cout << std::endl;
}

std::deque<std::pair<int, int> > PmergeMe::sortDeque(std::deque<std::pair<int, int> > deque) {
	if (deque.size() < 2) 
		return deque;
	std::deque<std::pair<int, int> > a;
	std::deque<std::pair<int, int> > b;
	std::deque<int> aIdx; // a 인덱스 임시저장 
	std::pair<int, int> lastB = std::make_pair(-1, -1);

	if (deque.size() % 2 != 0) {
		lastB = deque.back();
		deque.pop_back();		
	}

	int tempIdx = 0;

	while (deque.size() > 0) {
		std::pair<int, int> n1 = deque.front();
		deque.pop_front();
		std::pair<int, int> n2 = deque.front();
		deque.pop_front();
		if (n1.first > n2.first) {
			aIdx.push_back(n1.second);
			a.push_back(std::make_pair(n1.first, tempIdx));
			b.push_back(n2);
		} else {
			aIdx.push_back(n2.second);
			a.push_back(std::make_pair(n2.first, tempIdx));
			b.push_back(n1);
		}
		tempIdx++;
	}

	std::deque<std::pair<int, int> > sortedA = sortDeque(a); //메인 체인
	std::deque<std::pair<int, int> > sortedB;

	std::deque<std::pair<int, int> >::iterator iter;
	for (iter = sortedA.begin(); iter != sortedA.end(); iter++) {
		int idx = (*iter).second;
		(*iter).second = aIdx[idx];
		sortedB.push_back(b[idx]);
	}

	if (lastB.first > 0)
		sortedB.push_back(lastB);

	sortedA.push_front(sortedB.front()); 

	unsigned long toInsertIdx = 1; // 두번째 수부터 다 넣어야함 (순서 상관없이)
	int n = 2; // 어떤 수부터 넣어줄 지 정할 때 제곱수 

	while (toInsertIdx < sortedB.size()) {
		unsigned long startIdx = toInsertIdx + ((pow(2, n) - 1) - 2 * toInsertIdx) ;
		if (startIdx >= sortedB.size())
			startIdx = sortedB.size() - 1;
		unsigned long nextToInsertIdx = startIdx + 1;
		int mainSize = pow(2, n) - 1; // 내가 봐야할 길이 

		while (startIdx >= toInsertIdx) {
			// sortedB에 있는 startIdx의 친구를 메인 체인에 넣을거임 
			// sortedB[startIdx].first 가 sortedA 앞 mainSize에서 어디에 들어가야하는지 
			int pos = binarySearch(sortedA, mainSize, sortedB[startIdx].first);
			sortedA.insert(sortedA.begin() + pos, sortedB[startIdx]);
			startIdx--;
		}

		toInsertIdx = nextToInsertIdx;
		n++;
	}

	return sortedA;
}

// value가 들어갈 곳을 찾음
int PmergeMe::binarySearch(std::deque<std::pair<int, int> > deque, int mainSize, int value) {
	int low = 0;
	int high = mainSize - 1;
	int mid = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		if (value < deque[mid].first)
			high = mid - 1;
		else if (value > deque[mid].first)
			low = mid + 1;
		else
			return mid;
	}
	return low; // value가 들어갈 자리
}