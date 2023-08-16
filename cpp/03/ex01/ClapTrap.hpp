#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap 
{
protected:
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
};

#endif