#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string name);
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif