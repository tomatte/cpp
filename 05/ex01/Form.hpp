#ifndef FORM_H
# define FORM_H
# include <string>
# include <stdexcept>
# include <iostream>

class Form
{
	private:
		std::string	_name;
		bool		_signed;
		int const	_sign_grade;
		int const	_execution_grade;

		void	error_check(void) const;
	
	public:
		Form(void);
		Form(std::string name, int sign_grade, int execution_grade);
		Form(Form const & rhs);
		~Form(void);

		std::string	get_name(void) const;
		bool		get_signed(void) const;
		int			get_sign_grade(void) const;
		int			get_execution_grade(void) const;

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

		Form & operator=(Form const & rhs);
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif