#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
	std::cout<<"Cat has been created."<<std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy.type)
{
	brain = new Brain();
	*brain = *copy.brain;
	std::cout<<"Cat has been created."<<std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	type = ref.type;
	*brain = *ref.brain;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout<<"Cat has been destroyed."<<std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"Meow"<<std::endl;
}