
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
	
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &orig );
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &src);

		void attack(const std::string& target);
		void guardGate();
};

#endif