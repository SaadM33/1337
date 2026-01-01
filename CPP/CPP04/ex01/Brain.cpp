
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "insert idea here";
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdea(std::string idea)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = idea;
	}
	
}

void Brain::getIdeas() const
{
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Idea " << i + 1 << ": " << this->ideas[i] << std::endl;
	}
}