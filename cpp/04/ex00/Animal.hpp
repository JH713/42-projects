#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
private:
protected:
	std::string type;
public:
	Animal(std::string type = "Animal");
	Animal(const Animal& copy);
	Animal& operator=(const Animal& ref);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif