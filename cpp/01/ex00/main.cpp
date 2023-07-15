#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("zombie1");
	zombie1->announce();
	randomChump("zombie2");
	Zombie *zombie3 = newZombie("zombie3");
	zombie3->announce();
	delete zombie3;
	zombie1->announce();
	delete zombie1;
}