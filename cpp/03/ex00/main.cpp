#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap one("one");
	ClapTrap two("two");

	one.attack("two");
	two.takeDamage(0);
	two.beRepaired(10);
	one.printInfo();
	two.printInfo();
	return (0);
}