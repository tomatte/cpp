#ifndef AMATERIA_H
# define AMATERIA_H
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string const type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & rhs);
		~AMateria(void);
		
		AMateria & operator=(AMateria const & rhs);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif