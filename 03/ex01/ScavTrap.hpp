#ifndef SCAVTRAP
# define SCAVTRAP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & rhs);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

};

#endif