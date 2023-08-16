#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}
Ice::Ice(Ice& copy) : AMateria(copy.type) {}
Ice& Ice::operator=(Ice& ref)
{ 
	type = ref.type; 
	return (*this);
}
Ice::~Ice() {}

AMateria* Ice::clone() const
{
	AMateria* ice = new Ice();
	return (ice);
}

void Ice::use(ICharacter& target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}