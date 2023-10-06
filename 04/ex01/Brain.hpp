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

		Brain & 	operator=(Brain const & rhs);
		void		set_idea(int index, std::string const & idea);
		std::string	get_idea(int index) const;
};

#endif