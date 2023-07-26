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
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout<<"Brain has been created."<<std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = ref.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	delete []ideas;
	std::cout<<"Brain has been destroyed."<<std::endl;
}

void Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
	if (i < 0 || i > 99)
		return ("out of brain!!!");
	else
		return (ideas[i]);
}