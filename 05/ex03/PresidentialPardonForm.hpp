#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);

		void	execute(Bureaucrat const & executor) const;
	
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
};

#endif