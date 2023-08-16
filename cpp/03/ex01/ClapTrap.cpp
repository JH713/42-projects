#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<<"ClapTrap "<<name<<" has been created."<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout<<"ClapTrap copy of"<<name<<" has been created."<<std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap "<<name<<" has been destroyed."<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout<<"ClapTrap "<<name<<"can't do anything."<<std::endl;
		return ;
	}
	energyPoints--;
	std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "
		<<attackDamage<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout<<"ClapTrap "<<name<<" has taken "<<amount<<" damage."<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout<<"ClapTrap "<<name<<" can't do anything."<<std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout<<"ClapTrap "<<name<<" has recovered "<<amount<<" hit points."<<std::endl;
}

void ClapTrap::printInfo(void) const
{
	std::cout<<std::endl;
	std::cout<<"-----ClapTrap info-----"<<std::endl;
	std::cout<<"Name: "<<name<<std::endl;
	std::cout<<"Hit points: "<<hitPoints<<std::endl;
	std::cout<<"Energy points: "<<energyPoints<<std::endl;
	std::cout<<"Attack damage: "<<attackDamage<<std::endl;
	std::cout<<std::endl;
}
