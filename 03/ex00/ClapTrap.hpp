#ifndef CLAPTRAP
# define CLAPTRAP

# include <iostream>

class ClapTrap {
	private:
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
		
		static ClapTrap *clap_traps[15];
		static int		total;
		static void		store_clap_trap(ClapTrap *clap_trap);

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & rhs);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif