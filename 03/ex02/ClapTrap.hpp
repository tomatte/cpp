#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	private:

		static ClapTrap *clap_traps[15];
		static int		total;

	protected:
		std::string		name;
		int				hit_points;
		int				energy_points;
		int				attack_damage;
		static void		store_clap_trap(ClapTrap *clap_trap);
		static ClapTrap	*find_clap_trap(std::string const & name);
		bool			can_act(void) const;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & rhs);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		std::string	get_name(void) const;
		int			get_hit_points(void) const;
		bool		is_dead(void) const;
};

#endif