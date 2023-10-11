#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name(""), _grade(75)
{
	this->error_check();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	this->error_check();
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade)
{
	this->error_check();
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs._grade;
	this->_name = rhs._name;
	return (*this);
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

void	Bureaucrat::error_check(void) const
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::increment_grade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void		Bureaucrat::decrement_grade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}
