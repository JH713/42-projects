#include <iostream>

enum
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void etc(void);
public:
	void complain(std::string level);
};