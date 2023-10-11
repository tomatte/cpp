#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <stdexcept>
# include <string>

class AForm;

class Bureaucrat
{
	private:
		std::string	_name;
		int	_grade;

		void	error_check(void) const;

	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & rhs);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increment_grade(void);
		void		decrement_grade(void);
		void		signForm(AForm & form);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
