#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("zombie1");
	zombie1->announce();
	randomChump("zombie2");
	Zombie *zombie2 = newZombie("zombie3");
	zombie2->announce();
	delete zombie2;
	delete zombie1;
}