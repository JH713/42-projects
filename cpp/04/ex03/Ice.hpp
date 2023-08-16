#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice& copy);
	Ice& operator=(Ice& ref);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif