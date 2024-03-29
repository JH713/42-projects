#include "utils.hpp"

// 전체 다 숫자로 이루어져있는지 확인
static bool isNum(std::string str) {
	if (str.empty()) { return false; }
	for (int i = 0; i < static_cast<int>(str.length()); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

static bool isValidDate(int year, int month, int day) {
	int months[11] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int days[11] = {31, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 0 || year > 10000) { return false; }
	if (month < 1 || month > 12) { return false; }

	if (month == 2) {
		if (year % 4 == 0) {
			if (year % 100 == 0 && year % 400 != 0) {
				if (day < 0 || day > 28) { return false; }
				else { return true; } 
			} else {
				if (day < 0 || day > 29) { return false; }
				else { return true; } 
			}
		}
		if (day < 0 || day > 28) { return false; }
		else { return true; } 
	}

	for (int i = 0; i < 11; i++) {
		if (months[i] == month) {
			if (day < 0 || day > days[i]) { return false; }
			else { return true; }
		}
	}

	return false;
}

int changeDateToTime(std::string date) {
	std::istringstream ss(date);
	std::string year, month, day;

	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day);

	if (year.empty() || month.empty() || day.empty()) { return -1; }
	if (!isNum(year) || !isNum(month) || !isNum(day)) { return -1; }
	int yearNum = strToNum<int>(year);
	int monthNum = strToNum<int>(month);
	int dayNum = strToNum<int>(day);

	if (!isValidDate(yearNum, monthNum, dayNum)) { return -1; }

	int time = yearNum * 365 + monthNum * 31 + dayNum;

	return time;
}

bool isDouble(std::string str)
{
	if (str.empty())
		return false;
	if (str.length() > 10) // 10자리 넘어가는 것은 invalid한 input으로 처리 
		return false;
	if (isNum(str) || (str[0] == '-' && isNum(str.substr(1)) && str.length() > 1))
		return true;
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