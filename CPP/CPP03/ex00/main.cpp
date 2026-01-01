
#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap	cp1("dio");
	ClapTrap	cp2("jotaro");

	cp1.attack("joseph");
	cp2.takeDamage(5);
	cp1.beRepaired(3);

	return 0;
}