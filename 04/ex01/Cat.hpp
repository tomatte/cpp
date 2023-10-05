#ifndef CAT_H
# define CAT_H
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		Cat(void);
		Cat(Cat const & rhs);
		virtual ~Cat(void);

		Cat & operator=(Cat const & rhs);

		virtual void	makeSound(void) const;
};

#endif