#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs);
		~FragTrap(void);

		FragTrap & operator=(FragTrap const & rhs);

		void	attack(std::string const & target);
		void	highFivesGuys(void);
};

#endif