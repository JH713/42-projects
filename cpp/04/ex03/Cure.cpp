#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}
Cure::Cure(Cure& copy) : AMateria(copy.type) {}
Cure& Cure::operator=(Cure& ref)
{ 
	type = ref.type; 
	return (*this);
}
Cure::~Cure() {}

AMateria* Cure::clone() const
{
	AMateria* cure = new Cure();
	return (cure);
}

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}