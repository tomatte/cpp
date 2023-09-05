#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce( void );
};

#endif