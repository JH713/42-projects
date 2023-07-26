#include "AMateria.hpp"

AMateria::AMateria() : type("none") {}
AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::AMateria(AMateria& copy) : type(copy.type) {}
AMateria& AMateria::operator=(AMateria& ref) { type = ref.type; }
AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return (type); }
void AMateria::use(ICharacter& target)
{
	std::cout<<"* use a Materia to "<<target.getName()<<" *"<<std::endl;
}