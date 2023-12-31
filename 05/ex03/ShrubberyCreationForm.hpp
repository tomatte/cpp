#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		static std::string	getTree(void);

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;
	
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
};

#endif