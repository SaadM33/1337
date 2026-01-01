
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->fp = 50;
	this->atk = 30;

}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(src.ClapTrap::name), FragTrap(src.name), ScavTrap(src.name)
{
	this->name = src.name;
	this->hp = src.hp;
	this->fp = src.fp;
	this->atk = src.atk;
}

DiamondTrap::~DiamondTrap( void )
{
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		ClapTrap::name = src.ClapTrap::name;
		this->name = src.name;
		this->hp = src.hp;
		this->fp = src.fp;
		this->atk = src.atk;
	}
	return *this;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}
