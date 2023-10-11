#ifndef FORM_H
# define FORM_H
# include <string>

class Form
{
	private:
		std::string	_name;
		bool		_signed;
		int const	_sign_grade;
		int const	_execution_grade;
	
	public:
		Form(void);
		Form(Form const & rhs);
		~Form(void);

		Form & operator=(Form const & rhs);
};

#endif