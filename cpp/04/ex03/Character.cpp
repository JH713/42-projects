#include "Character.hpp"

Character::Character(std::string name) : name(name), trash(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(Character& copy) : name(copy.name), trash(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = copy.inventory[i]->clone();
}

Character& Character::operator=(Character& ref)
{
	name = ref.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			unequip(i);
		inventory[i] = ref.inventory[i]->clone();
	}
	if (trash)
	{
		delete trash;
		trash = 0;
	}
	if (ref.trash)
		trash = ref.trash->clone();
	return (*this);
}

Character::~Character() 
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const & Character::getName() const 
{ 
	return (name); 
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] == 0)
		return ;
	floor.append(inventory[idx]);
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx])
		inventory[idx]->use(target);
}