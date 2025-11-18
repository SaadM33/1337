
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:

		std::string	name;

	public:

		DiamondTrap( std::string name);
		DiamondTrap( const DiamondTrap &src );
		~DiamondTrap( void );

		DiamondTrap	&operator=(const DiamondTrap &src);

		void	attack( const std::string &target );
		void	whoAmI();

	using ClapTrap::hp;
	using ClapTrap::fp;
	using ClapTrap::atk;
};

#endif