#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure& copy);
	Cure& operator=(Cure& ref);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

Cure::Cure(): AMateria("cure") {}
Cure::Cure(Cure& copy) : AMateria(copy.type) {}
Cure& Cure::operator=(Cure& ref) { type = ref.type; }
Cure::~Cure() {}

AMateria* Cure::clone() const
{
	AMateria* cure = new Cure();
	//타입 가져오기
	return (cure);
}

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}

#endif