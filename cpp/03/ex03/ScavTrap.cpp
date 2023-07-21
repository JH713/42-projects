#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"ScavTrap "<<name<<" has been created."<<std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;
	std::cout<<"ScavTrap copy of"<<copy.getName()<<" has been created."<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
	setName(ref.getName());
	setHitPoints(ref.getHitPoints());
	setEnergyPoints(ref.getEnergyPoints());
	setAttackDamage(ref.getAttackDamage());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap "<<getName()<<" has been destroyed."<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0)
	{
		std::cout<<"ScavTrap "<<getName()<<"can't do anything."<<std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout<<"ScavTrap "<<getName()<<" attacks "<<target<<", causing "
		<<getAttackDamage()<<" points of damage!"<<std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() < amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout<<"ScavTrap "<<getName()<<" has taken "<<amount<<" damage."<<std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0)
	{
		std::cout<<"ScavTrap "<<getName()<<" can't do anything."<<std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	setHitPoints(getHitPoints() + amount);
	std::cout<<"ScavTrap "<<getName()<<" has recovered "<<amount<<" hit points."<<std::endl;
}

void ScavTrap::printInfo(void) const
{
	std::cout<<std::endl;
	std::cout<<"-----ScavTrap info-----"<<std::endl;
	std::cout<<"Name: "<<getName()<<std::endl;
	std::cout<<"Hit points: "<<getHitPoints()<<std::endl;
	std::cout<<"Energy points: "<<getEnergyPoints()<<std::endl;
	std::cout<<"Attack damage: "<<getAttackDamage()<<std::endl;
	std::cout<<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap "<<getName()<<" is now in Gatekeeper mode."<<std::endl;
}
