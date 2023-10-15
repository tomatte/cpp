#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);

		void	execute(Bureaucrat const & executor) const;
	
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
};

#endif