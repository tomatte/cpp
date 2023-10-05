#ifndef DOG_H
# define DOG_H
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;

	public:
		Dog(void);
		Dog(Dog const & rhs);
		virtual ~Dog(void);

		Dog & operator=(Dog const & rhs);

		virtual void	makeSound(void) const;
};

#endif