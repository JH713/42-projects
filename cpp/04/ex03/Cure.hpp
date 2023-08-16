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

#endif