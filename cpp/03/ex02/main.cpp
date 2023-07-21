#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap scav("Scav");
	FragTrap frag("Frag");

	scav.attack("Frag");
	frag.takeDamage(20);
	frag.attack("Clap");
	scav.takeDamage(30);

	scav.printInfo();
	frag.printInfo();
	frag.highFivesGuys();
	return (0);
}