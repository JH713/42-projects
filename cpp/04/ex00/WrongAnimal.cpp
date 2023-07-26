#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout<<"WrongAnimal has been created."<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	type = copy.type;
	std::cout<<"WrongAnimal has been created."<<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	type = ref.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal has been destroyed."<<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout<<"..."<<std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}