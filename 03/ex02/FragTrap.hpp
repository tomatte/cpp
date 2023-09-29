#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		bool	in_gate_keeper_mode;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs);
		~FragTrap(void);

		FragTrap & operator=(FragTrap const & rhs);

		void	attack(std::string const & target);
		void	guardGate(void);
};

#endif