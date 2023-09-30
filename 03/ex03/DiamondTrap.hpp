#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & rhs);
		~DiamondTrap(void);

		DiamondTrap & operator=(DiamondTrap const & rhs);

		void	attack(std::string const & target);
		void	whoAmI(void);
};

#endif