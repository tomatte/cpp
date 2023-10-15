#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include "ColorOut.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
AForm("PresidentialPardonForm", 25, 5), _target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : 
AForm(rhs), _target(rhs._target)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->verify_execution_requirements(executor);
	ColorOut::blue << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
}
