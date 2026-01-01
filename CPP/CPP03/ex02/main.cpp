
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main( void )
{
	FragTrap frag("atay_bi_na3na3");
	frag.attack("Enemy");
	frag.takeDamage(30);
	frag.beRepaired(15);
	frag.highFivesGuys();

	FragTrap clone_frag(frag);
	clone_frag.highFivesGuys();

	return 0;
}