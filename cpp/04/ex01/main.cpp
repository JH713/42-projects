#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	int animalNum = 4;
	Animal *animals = new Animal[animalNum];
	for (int i = 0; i < animalNum / 2; i++)
		animals[i] = Dog();
	for (int i = animalNum / 2; i < animalNum; i++)
		animals[i] = Dog();
	
	return (0);
}