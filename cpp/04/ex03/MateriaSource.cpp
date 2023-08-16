#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		storage[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource& copy)
{
	for(int i = 0; i < 4; i++)
		storage[i] = copy.storage[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource& ref)
{
	for(int i = 0; i < 4; i++)
		storage[i] = ref.storage[i];
	return (*this);
}

MateriaSource::~MateriaSource() 
{
	for(int i = 0; i < 4; i++)
	{
		if (storage[i])
			delete storage[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	int i = 0;
	while (i < 4)
	{
		if (storage[i] == 0)
		{
			storage[i] = materia;
			break ;
		}
		++i;
	}
	if (i == 4)
		std::cout<<"Storage is full!"<<std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == storage[i]->getType())
			return (storage[i]->clone());
	}
	return (0);
}