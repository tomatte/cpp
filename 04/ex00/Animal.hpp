#ifndef ANIMAL_H
# define ANIMAL_H
# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(Animal const & rhs);
		~Animal(void);

		Animal & operator=(Animal const & rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif