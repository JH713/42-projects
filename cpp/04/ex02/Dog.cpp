#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout<<"Dog has been created."<<std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy.type)
{
	brain = new Brain();
	*brain = *copy.brain;
	std::cout<<"Dog has been created."<<std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	type = ref.type;
	*brain = *ref.brain;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout<<"Dog has been destroyed."<<std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"Bark"<<std::endl;
}

void Dog::setBrainIdeas(std::string idea) const
{
	brain->setIdeas(idea);
}

std::string Dog::getBrainIdea(int i) const
{
	return (brain->getIdea(i));
}

Brain *Dog::getBrainPtr() const
{
	return (brain);
}