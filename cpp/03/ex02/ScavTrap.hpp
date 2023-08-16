#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
public:
	ScavTrap(std::string name="no name");
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &ref);
	~ScavTrap();

	void attack(const std::string& target);
	void printInfo() const;
	
	void guardGate();
};

#endif