#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void leaks(void)
{
	system("leaks brain");
}

int main()
{
	atexit(leaks);
	int animalNum = 4;
	Animal *animals = new Animal[animalNum];
	for (int i = 0; i < animalNum / 2; i++)
		animals[i] = Dog();
	for (int i = animalNum / 2; i < animalNum; i++)
		animals[i] = Cat();
	for (int i = 0; i < animalNum; i++)
		animals[i].getType();
	delete []animals;
	return (0);
}