
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		
		Weapon		wack;
		std::string	name;

		HumanA(std::string str, Weapon &weap);
		
	public:

		void 		attack(void);
};

#endif