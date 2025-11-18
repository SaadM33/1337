
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( std::string name) : ClapTrap( name )
{
	this->hp = 100;
	this->fp = 100;
	this->atk = 30;
	std::cout << "FragTrap " << this->name << " has arrived." << std::endl;
}

FragTrap::FragTrap( const FragTrap &orig ) : ClapTrap( orig )
{
	std::cout << "FragTrap " << this->name << " has been cloned." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " said bye bye." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->fp = src.fp;
		this->atk = src.atk;
	}
	return *this;
}

void	FragTrap::attack( const std::string &target )
{
	if (this->hp <= 0)
	{
		std::cout << "FragTrap " << this->name << " is dead (rip)." << std::endl;
		return ;
	}
	else if (this->fp <= 0)
	{
		std::cout << "FragTrap " << this->name << " has no mana left to attack." << std::endl;
		return ;
	}
	this->fp--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->atk << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	if (this->hp <= 0)
		std::cout << "FragTrap " << this->name << " is dead (rip)." << std::endl;
	else
		std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
}