#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap 
{
private:
	std::string name;
	unsigned int			hitPoints;
	unsigned int			energyPoints;
	unsigned int			attackDamage;
public:
	ClapTrap(std::string name = "no name");
	ClapTrap(const ClapTrap &copy);
	ClapTrap& operator=(const ClapTrap &ref);
	~ClapTrap();
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	void printInfo() const;
	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	void setName(std::string name);
	void setHitPoints(unsigned int num);
	void setEnergyPoints(unsigned int num);
	void setAttackDamage(unsigned int num);
};

#endif