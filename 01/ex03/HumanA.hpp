#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {
	Weapon &	weapon;
	std::string	name;
	public:
		HumanA(std::string name, Weapon & w);
		~HumanA(void);
	
		void	attack(void) const;
};

#endif