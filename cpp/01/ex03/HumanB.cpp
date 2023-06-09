#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

void HumanB::attack()
{
	if ((*weapon).getType() == "")
		std::cout<<name<<" doesn't have weapon."<<std::endl;
	else
		std::cout<<name<< " attacks with their "<<(*weapon).getType()<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}