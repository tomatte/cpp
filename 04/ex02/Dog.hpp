#ifndef DOG_H
# define DOG_H
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*brain;

	public:
		Dog(void);
		Dog(Dog const & rhs);
		virtual ~Dog(void);

		Dog & operator=(Dog const & rhs);

		virtual void	makeSound(void) const;
		void			set_idea(int index, std::string const & idea);
		std::string		get_idea(int index) const;
};

#endif