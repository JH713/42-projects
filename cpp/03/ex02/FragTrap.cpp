#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"FragTrap "<<name<<" has been created."<<std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout<<"FragTrap copy of"<<copy.getName()<<" has been created."<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
	setName(ref.getName());
	setHitPoints(ref.getHitPoints());
	setEnergyPoints(ref.getEnergyPoints());
	setAttackDamage(ref.getAttackDamage());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap "<<getName()<<" has been destroyed."<<std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0)
	{
		std::cout<<"FragTrap "<<getName()<<"can't do anything."<<std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout<<"FragTrap "<<getName()<<" attacks "<<target<<", causing "
		<<getAttackDamage()<<" points of damage!"<<std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() < amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout<<"FragTrap "<<getName()<<" has taken "<<amount<<" damage."<<std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0)
	{
		std::cout<<"FragTrap "<<getName()<<" can't do anything."<<std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	setHitPoints(getHitPoints() + amount);
	std::cout<<"FragTrap "<<getName()<<" has recovered "<<amount<<" hit points."<<std::endl;
}

void FragTrap::printInfo(void) const
{
	std::cout<<std::endl;
	std::cout<<"-----FragTrap info-----"<<std::endl;
	std::cout<<"Name: "<<getName()<<std::endl;
	std::cout<<"Hit points: "<<getHitPoints()<<std::endl;
	std::cout<<"Energy points: "<<getEnergyPoints()<<std::endl;
	std::cout<<"Attack damage: "<<getAttackDamage()<<std::endl;
	std::cout<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<"High five, please!🙌"<<std::endl;
}
