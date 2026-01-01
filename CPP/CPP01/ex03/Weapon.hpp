
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		
		std::string type;
	
	public:

		Weapon(std::string str);
		
		const std::string	&getType(void) const;

		void 				setType(std::string value);
};

#endif