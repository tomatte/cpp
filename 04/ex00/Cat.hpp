#ifndef CAT_H
# define CAT_H
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & rhs);
		~Cat(void);

		Cat & operator=(Cat const & rhs);
};

#endif