
#include <iostream>
#include "Character.hpp"
	
Character::Character( std::string name )
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::Character( const Character &other)
{
	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inv[i])
			this->inv[i] = other.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inv[i])
				delete this->inv[i];
			if (other.inv[i])
				this->inv[i] = other.inv[i]->clone();
			else
				this->inv[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] == NULL)
		{
			this->inv[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	this->inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->inv[idx] == NULL)
		return;
	this->inv[idx]->use(target);
}
