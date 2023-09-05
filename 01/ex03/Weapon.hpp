#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
	std::string	type;
	public:
		Weapon(std::string w_type);
		~Weapon(void);

		std::string &	getType(void);
		void	setType(std::string new_type);
};

#endif