#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "LinkedList.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];
	LinkedList floor;
public:
	AMateria *trash;
	Character(std::string name = "no name");
	Character(Character& copy);
	Character& operator=(Character& ref);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif