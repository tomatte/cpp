#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ColorOut.hpp"

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

void		Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		ColorOut::green << "o ";
		std::cout << this->getName() << " signed " << form.getName() << "\n";
	}
	catch(std::exception & e)
	{
		ColorOut::yellow << "! ";
		std::cout << this->getName() << " couldn't sign " << form.getName() \
		<< " because " << e.what() << "\n";
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		ColorOut::green << "o ";
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		ColorOut::yellow << "! ";
		std::cout << this->getName() << " failed to execute " << 
			form.getName() << ": " << e.what() << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}
