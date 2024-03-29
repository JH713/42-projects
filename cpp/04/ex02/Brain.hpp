#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string *ideas;
public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& ref);
	~Brain();

	void setIdeas(std::string idea);
	std::string getIdea(int i);
};

#endif