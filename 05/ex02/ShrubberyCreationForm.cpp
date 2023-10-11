#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
AForm("ShrubberyCreationForm", 145, 137), _target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : 
AForm(rhs), _target(rhs._target)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}
