#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & rhs);
		~WrongAnimal(void);

		WrongAnimal & operator=(WrongAnimal const & rhs);

		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif