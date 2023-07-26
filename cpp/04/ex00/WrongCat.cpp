#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout<<"WrongCat has been created."<<std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy.type)
{
	std::cout<<"WrongCat has been created."<<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	type = ref.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat has been destroyed."<<std::endl;
}

void WrongCat::makeSound() const
{
	std::cout<<"Meow"<<std::endl;
}