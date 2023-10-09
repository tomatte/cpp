#ifndef AMATERIA_H
# define AMATERIA_H
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string const type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & rhs);
		virtual ~AMateria(void);
		
		AMateria & operator=(AMateria const & rhs);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		void	put_on_ground(AMateria *m);
		void	clear_ground(void);
};

#endif