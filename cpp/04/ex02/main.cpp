#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void leaks(void)
{
	system("leaks brain");
}

int main()
{
	// atexit(leaks);
	// const Animal *animal = new Animal("animal");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	std::cout <<"------------------------------"<<std::endl;

	int animalNum = 4;
	Animal *animals[animalNum];
	for (int i = 0; i < animalNum / 2; i++)
		animals[i] = new Dog();
	for (int i = animalNum / 2; i < animalNum; i++)
		animals[i] = new Cat();
	for (int i = 0; i < animalNum; i++)
		std::cout << animals[i]->getType() << std::endl;
	for (int i = 0; i < animalNum; i++)
		delete animals[i];

	std::cout <<"------------------------------"<<std::endl;

	Dog dog1;
	dog1.setBrainIdeas("Bone!");
	Dog dog2(dog1);
	std::cout<<"dog1's thought: "<<dog1.getBrainIdea(0)<<std::endl;
	std::cout<<"dog2's thought: "<<dog2.getBrainIdea(0)<<std::endl;
	std::cout<<"dog1's brain: "<<dog1.getBrainPtr()<<std::endl;
	std::cout<<"dog2's brain: "<<dog2.getBrainPtr()<<std::endl;

	return 0;
}