#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");

	clap.attack("Scav");
	scav.takeDamage(0);
	scav.attack("Clap");
	clap.takeDamage(20);

	clap.printInfo();
	scav.printInfo();
	scav.guardGate();
	return (0);
}