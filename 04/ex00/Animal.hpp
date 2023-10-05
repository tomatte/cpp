#ifndef ANIMAL_H
# define ANIMAL_H
# include <string>

class Animal
{
	protected:
		std::string type;
		std::string	sound;

	public:
		Animal(void);
		Animal(Animal const & rhs);
		~Animal(void);

		Animal & operator=(Animal const & rhs);

		void	makeSound(void) const;
};

#endif