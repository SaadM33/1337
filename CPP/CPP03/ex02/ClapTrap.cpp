
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( std::string name ) : name(name), hp(10), fp(10), atk(0)
{
	std::cout << "\033[31mClapTrap " << this->name << " IS INVADING.\033[0m" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &orig)
{
	this->name = orig.name;
	this->hp = orig.hp;
	this->fp = orig.fp;
	this->atk = orig.atk;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[33mClapTrap " << this->name << " IS SLAIN.\033[0m" <<  std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead." << std::endl;
		return ;
	}
	else if (this->fp == 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack." << std::endl;
		return ;
	}
	this->fp--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->atk << " damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead." << std::endl;
		return ;
	}
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead." << std::endl;
		return ;
	}
	else if (this->fp == 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired." << std::endl;
		return ;
	}
	this->fp--;
	this->hp += amount;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " hp!" << std::endl;
}