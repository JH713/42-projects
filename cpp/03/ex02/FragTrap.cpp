#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"FragTrap "<<name<<" has been created."<<std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout<<"FragTrap copy of"<<name<<" has been created."<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap "<<name<<" has been destroyed."<<std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout<<"FragTrap "<<name<<"can't do anything."<<std::endl;
		return ;
	}
	--energyPoints;
	std::cout<<"FragTrap "<<name<<" attacks "<<target<<", causing "
		<<attackDamage<<" points of damage!"<<std::endl;
}

void FragTrap::printInfo(void) const
{
	std::cout<<std::endl;
	std::cout<<"-----FragTrap info-----"<<std::endl;
	std::cout<<"Name: "<<name<<std::endl;
	std::cout<<"Hit points: "<<hitPoints<<std::endl;
	std::cout<<"Energy points: "<<energyPoints<<std::endl;
	std::cout<<"Attack damage: "<<attackDamage<<std::endl;
	std::cout<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout<<"FragTrap "<<name<<"can't do anything."<<std::endl;
		return ;
	}
	std::cout<<"High five, please!🙌"<<std::endl;
}
