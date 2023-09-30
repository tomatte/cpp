#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	in_gate_keeper_mode;

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & rhs);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		void	attack(std::string const & target);
		void	guardGate(void);
};

#endif