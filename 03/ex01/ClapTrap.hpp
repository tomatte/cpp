#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	private:
		static ClapTrap *clap_traps[15];
		static int		total;

	protected:
		static void		store_clap_trap(ClapTrap *clap_trap);
		static ClapTrap	*find_clap_trap(std::string const & name);

		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
		bool		can_act(void) const;
		void		set_hit_points(int amount);
		void		set_energy_points(int amount);
		void		set_attack_damage(int amount);
		void		sum_energy_points(int amunt);
		int			get_energy_points(void);
		int			get_attack_damage(void);


	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & rhs);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		std::string	get_name(void);
};

#endif