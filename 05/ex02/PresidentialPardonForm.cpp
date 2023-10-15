#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include "ColorOut.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
AForm("presidential pardon", 25, 5)
{
	this->setTarget("none");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("presidential pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : 
AForm(rhs)
{
	this->setTarget(rhs.getTarget());
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	AForm::operator=(rhs);
	this->setTarget(rhs.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->verify_execution_requirements(executor);
	ColorOut::blue << "* " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox *\n";
}
