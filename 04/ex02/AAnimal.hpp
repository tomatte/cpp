#ifndef AANIMAL_H
# define AANIMAL_H
# include <string>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const & rhs);
		virtual ~AAnimal(void);

		AAnimal & operator=(AAnimal const & rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif