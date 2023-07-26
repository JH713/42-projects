#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *storage[4];
public:
	MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		storage[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* meteria)
{
	AMateria* copy = meteria->clone();
	int i = 0;
	while (i < 4)
	{
		if (storge[i] == NULL)
		{
			
		}
		++i;
	}
}

#endif