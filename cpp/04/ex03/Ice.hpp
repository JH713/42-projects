#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	Ice();
	Ice(Ice& copy);
	Ice& operator=(Ice& ref);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

Ice::Ice(): AMateria("ice") {}
Ice::Ice(Ice& copy) : AMateria(copy.type) {}
Ice& Ice::operator=(Ice& ref) { type = ref.type; }
Ice::~Ice() {}

AMateria* Ice::clone() const
{
	AMateria* ice = new Ice();
	//타입 가져오기
	return (ice);
}

void Ice::use(ICharacter& target)
{
	std::cout<<"*  shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

#endif