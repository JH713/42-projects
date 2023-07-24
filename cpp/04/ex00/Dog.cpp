#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout<<"Dog has been created."<<std::endl;
}

Dog::Dog(const Dog& copy)
{
	*this = copy;
	std::cout<<"Dog has been created."<<std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	type = ref.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout<<"Dog has been destroyed."<<std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"Bark"<<std::endl;
}