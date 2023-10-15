#include "Form.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

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

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSigned(void) const
{
	return (this->_signed);
}

int			Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int			Form::getExecutionGrade(void) const
{
	return (this->_execution_grade);
}

void		Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << "*FORM DATA*\n";
	o << "name: " << rhs.getName() << "\n";
	o << "signed: " << rhs.getSigned() << "\n";
	o << "sign grade: " << rhs.getSignGrade() << "\n";
	o << "execution grade: " << rhs.getExecutionGrade() << "\n";
	return (o); 
}
