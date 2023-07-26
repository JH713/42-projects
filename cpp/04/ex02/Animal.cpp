#include "Animal.hpp"

Animal::Animal(std::string type) : type(type)
{
	std::cout<<"Animal has been created."<<std::endl;
}

Animal::Animal(const Animal& copy)
{
	type = copy.type;
	std::cout<<"Animal has been created."<<std::endl;
}

Animal& Animal::operator=(const Animal& ref)
{
	type = ref.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout<<"Animal has been destroyed."<<std::endl;
}

std::string Animal::getType() const
{
	return (type);
}