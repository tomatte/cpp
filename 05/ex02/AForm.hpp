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
		std::string const	_name;
		bool		_signed;
		int const	_sign_grade;
		int const	_execution_grade;

		void	error_check(void) const;

	protected:
		void	verify_execution_requirements(Bureaucrat const & executor) const;
	
	public:
		virtual ~AForm(void) = 0;
		AForm(std::string name, int sign_grade, int execution_grade);
		AForm(AForm const & rhs);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecutionGrade(void) const;
		void		beSigned(Bureaucrat & b);

		virtual void	execute(Bureaucrat const & executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		AForm & operator=(AForm const & rhs);
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif