#ifndef CHARACTER_H
# define CHARACTER_H
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>
# define MAX_ITEMS 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_invetory[MAX_ITEMS];

		static void	clear_inventory(AMateria *_invetory[MAX_ITEMS]); //ok

	public:
		Character(void); //ok
		Character(std::string const & name);
		Character(Character const & rhs); //ok
		~Character(void); //ok

		Character & operator=(Character const & rhs); //ok
		std::string	const & getName() const; //ok
		void 				equip(AMateria* m); //ok
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
};

#endif