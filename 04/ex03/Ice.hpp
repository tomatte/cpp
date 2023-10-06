#ifndef ICE_H
# define ICE_H
# include "AMateria.hpp"

class Ice : AMateria
{
	public:
		Ice(void);
		Ice(Ice const & rhs);
		~Ice(void);

		Ice & operator=(Ice const & rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif