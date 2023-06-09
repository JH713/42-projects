#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void setName(std::string name);
	void announce(void);
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif