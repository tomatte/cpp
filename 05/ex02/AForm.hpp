#ifndef FORM_H
# define FORM_H
# include <string>
# include <stdexcept>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		AForm(void);
		std::string	_name;
		bool		_signed;
		int const	_sign_grade;
		int const	_execution_grade;

		void	error_check(void) const;
	
	public:
		AForm(void);
		AForm(std::string name, int sign_grade, int execution_grade);
		AForm(AForm const & rhs);
		virtual ~AForm(void) = 0;

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecutionGrade(void) const;
		void		beSigned(Bureaucrat & b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		AForm & operator=(AForm const & rhs);
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif