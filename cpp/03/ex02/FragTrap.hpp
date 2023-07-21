#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
public:
	FragTrap(std::string name="no name");
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &ref);
	~FragTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printInfo() const;
	
	void highFivesGuys(void);
};

#endif