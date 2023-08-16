#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *storage[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource& copy);
	MateriaSource& operator=(MateriaSource& ref);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif