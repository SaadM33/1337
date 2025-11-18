
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	ScavTrap scav("cheese");
	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(15);
	scav.guardGate();
	
	ScavTrap copy(scav);
	copy.guardGate();
	
	return 0;
}