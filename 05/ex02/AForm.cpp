#include "AForm.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _signed(false),
_sign_grade(1), _execution_grade(1)
{
	this->error_check();
}

AForm::AForm(std::string name, int sign_grade, int execution_grade) :
_name(name), _signed(false), _sign_grade(sign_grade), _execution_grade(execution_grade)
{
	this->error_check();
}

AForm::AForm(AForm const & rhs) : _name(rhs._name), _signed(rhs._signed),
_sign_grade(rhs._sign_grade), _execution_grade(rhs._execution_grade)
{
	this->error_check();
}

AForm::~AForm(void)
{
}

AForm & AForm::operator=(AForm const & rhs)
{
	this->_name = rhs._name;
	this->_signed = rhs._signed;
	return (*this);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high.";
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low.";
}

void	AForm::error_check(void) const
{
	if (this->_execution_grade < 1 || this->_sign_grade < 1)
		throw AForm::GradeTooHighException();
	if (this->_execution_grade > 150 || this->_sign_grade > 150)
		throw AForm::GradeTooLowException();
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSigned(void) const
{
	return (this->_signed);
}

int			AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int			AForm::getExecutionGrade(void) const
{
	return (this->_execution_grade);
}

void		AForm::beSigned(Bureaucrat & b)
{
	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream & o, AForm const & rhs)
{
	o << "*FORM DATA*\n";
	o << "name: " << rhs.getName() << "\n";
	o << "signed: " << rhs.getSigned() << "\n";
	o << "sign grade: " << rhs.getSignGrade() << "\n";
	o << "execution grade: " << rhs.getExecutionGrade() << "\n";
	return (o); 
}
