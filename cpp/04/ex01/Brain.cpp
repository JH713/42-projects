#include "Brain.hpp"

Brain::Brain() 
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = "thoughts";
	std::cout<<"Brain has been created."<<std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout<<"Brain has been created."<<std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = ref.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	delete []ideas;
	std::cout<<"Brain has been destroyed."<<std::endl;
}