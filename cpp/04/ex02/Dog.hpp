#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& ref);
	~Dog();

	void makeSound() const;
	void setBrainIdeas(std::string idea) const;
	std::string getBrainIdea(int i) const;
	Brain *getBrainPtr() const;
};

#endif