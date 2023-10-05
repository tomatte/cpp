#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
	protected:
		std::string	ideas[100];

	public:
		Brain(void);
		Brain(Brain const & rhs);
		~Brain(void);

		Brain & operator=(Brain const & rhs);
};

#endif