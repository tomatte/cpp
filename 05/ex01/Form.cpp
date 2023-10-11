#include "Form.hpp"
# include <string>
# include <stdexcept>
# include <iostream>

Form::Form(void) : _name("Default"), _signed(false),
_sign_grade(1), _execution_grade(1)
{
	this->error_check();
}

Form::Form(std::string name, int sign_grade, int execution_grade) :
_name(name), _signed(false), _sign_grade(sign_grade), _execution_grade(execution_grade)
{
	this->error_check();
}

Form::Form(Form const & rhs) : _name(rhs._name), _signed(rhs._signed),
_sign_grade(rhs._sign_grade), _execution_grade(rhs._execution_grade)
{
	this->error_check();
}

Form::~Form(void)
{
}

Form & Form::operator=(Form const & rhs)
{
	this->_name = rhs._name;
	this->_signed = rhs._signed;
	return (*this);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high.";
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low.";
}

void	Form::error_check(void) const
{
	if (this->_execution_grade < 1 || this->_sign_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_execution_grade > 150 || this->_sign_grade > 150)
		throw Form::GradeTooLowException();
}

std::string	Form::get_name(void) const
{
	return (this->_name);
}

bool		Form::get_signed(void) const
{
	return (this->_signed);
}

int			Form::get_sign_grade(void) const
{
	return (this->_sign_grade);
}

int			Form::get_execution_grade(void) const
{
	return (this->_execution_grade);
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << "*FORM DATA*\n";
	o << "name: " << rhs.get_name() << "\n";
	o << "signed: " << rhs.get_signed() << "\n";
	o << "sign grade: " << rhs.get_sign_grade() << "\n";
	o << "execution grade: " << rhs.get_execution_grade() << "\n";
	return (o); 
}
