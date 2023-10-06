#ifndef WRONGCAT_H
# define WRONGCAT_H
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const & rhs);
		~WrongCat(void);

		WrongCat & operator=(WrongCat const & rhs);

		void	makeSound(void) const;
};

#endif