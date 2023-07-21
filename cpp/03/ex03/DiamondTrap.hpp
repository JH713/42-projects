#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string name="no name");
};

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap(), name(name)
{
	setName(name + "_clap_name");
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints()
}

#endif