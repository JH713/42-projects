#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"ScavTrap "<<name<<" has been created."<<std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;
	std::cout<<"ScavTrap copy of"<<name<<" has been created."<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap "<<name<<" has been destroyed."<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout<<"ScavTrap "<<name<<"can't do anything."<<std::endl;
		return ;
	}
	--energyPoints;
	std::cout<<"ScavTrap "<<name<<" attacks "<<target<<", causing "
		<<attackDamage<<" points of damage!"<<std::endl;
}

void ScavTrap::printInfo(void) const
{
	std::cout<<std::endl;
	std::cout<<"-----ScavTrap info-----"<<std::endl;
	std::cout<<"Name: "<<name<<std::endl;
	std::cout<<"Hit points: "<<hitPoints<<std::endl;
	std::cout<<"Energy points: "<<energyPoints<<std::endl;
	std::cout<<"Attack damage: "<<attackDamage<<std::endl;
	std::cout<<std::endl;
}

void ScavTrap::guardGate()
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout<<"ScavTrap "<<name<<"can't do anything."<<std::endl;
		return ;
	}
	std::cout<<"ScavTrap "<<name<<" is now in Gatekeeper mode."<<std::endl;
}
