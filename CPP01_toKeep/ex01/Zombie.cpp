
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "A zombie is created!" << std::endl;
	return ;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}