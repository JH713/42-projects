#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout<<"Cat has been created."<<std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy.type)
{
	std::cout<<"Cat has been created."<<std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	type = ref.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout<<"Cat has been destroyed."<<std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"Meow"<<std::endl;
}