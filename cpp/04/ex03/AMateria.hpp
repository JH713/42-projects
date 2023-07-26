#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"


class AMateria
{
private:
	AMateria();
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	AMateria(AMateria& copy);
	AMateria& operator=(AMateria& ref);
	~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif