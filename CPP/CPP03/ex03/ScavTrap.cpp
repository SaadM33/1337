
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->hp = 100;
	this->fp = 50;
	this->atk = 20;
	std::cout << "ScavTrap " << this->name << " has arrived." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &orig ) : ClapTrap( orig )
{
	std::cout << "ScavTrap " << this->name << " has been cloned." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " said bye bye." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
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

void	ScavTrap::attack( const std::string &target )
{
	if (this->hp <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead (rip)." << std::endl;
		return ;
	}
	if (this->fp <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no mana left to attack." << std::endl;
		return ;
	}
	this->fp--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->atk << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	if (this->hp <= 0)
		std::cout << "ScavTrap " << this->name << " is dead (rip)." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " has entered Gate Keeper mode." << std::endl;
}