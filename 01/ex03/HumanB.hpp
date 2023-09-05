#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {
	Weapon *	weapon;
	std::string	name;
	public:
		HumanB(std::string name);
		~HumanB(void);
	
		void	attack(void) const;
		void	setWeapon(Weapon & w);
};

#endif