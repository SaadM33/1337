
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:

		std::string	name;

		int			hp;
		int			fp;
		int			atk;

	public:

		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &orig );
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif