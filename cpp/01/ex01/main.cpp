#include "Zombie.hpp"

int main(void)
{
	int n = 5;
	Zombie *zombieArr = zombieHorde(n, "zom");
	for(int i = 0; i < n; ++i)
	{
		std::cout<<i<<" : ";
		zombieArr[i].announce(); 
	}
	delete []zombieArr;
}