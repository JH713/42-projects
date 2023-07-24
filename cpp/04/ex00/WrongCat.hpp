#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
	WrongCat();
	WrongCat(const WrongCat& copy);
	WrongCat& operator=(const WrongCat& ref);
	~WrongCat();

	void makeSound() const;
};

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout<<"WrongCat has been created."<<std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
	*this = copy;
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

#endif