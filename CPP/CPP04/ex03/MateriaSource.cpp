
#include <iostream>
#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.memory[i])
			memory[i] = other.memory[i]->clone();
		else
			memory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i])
				delete memory[i];
			if (other.memory[i])
				memory[i] = other.memory[i]->clone();
			else
				memory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (memory[i])
			delete memory[i];
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (memory[i] == NULL)
		{
			memory[i] = materia;
			return;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (memory[i] && memory[i]->getType() == type)
			return memory[i]->clone();
	}
	return NULL;
}
