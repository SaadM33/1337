#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level)
{

	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "wong in put" << std::endl;
		return ;
	}

	switch (level[0])
	{
		case 'D':
			debug();
			// fallthrough
		case 'I':
			info();
			// fall through
		case 'W':
			warning();
			// fall through
		case 'E':
			error();
			break;

		default:
			std::cout << "wong in put" << std::endl;
	}
	
}
