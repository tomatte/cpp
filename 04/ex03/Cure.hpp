#ifndef CURE_H
# define CURE_H
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & rhs);
		Cure(AMateria const & rhs);
		~Cure(void);

		Cure & operator=(Cure const & rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif