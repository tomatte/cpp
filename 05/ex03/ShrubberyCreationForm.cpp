#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

 std::string	ShrubberyCreationForm::getTree(void)
{
	std::string tree = "               ,@@@@@@@,\n \
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n \
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n \
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n \
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n \
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n \
   `&%\\ ` /%&'    |.|        \\ '|8'\n \
       |o|        | |         | |\n \
       |.|        | |         | |\n \
     \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\\\n";

	return (tree);
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
AForm("shrubbery creation", 145, 137)
{
	setTarget("none");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("shrubbery creation", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : 
AForm(rhs)
{
	this->setTarget(rhs.getTarget());
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	AForm::operator=(rhs);
	this->setTarget(rhs.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	file;
	std::string		file_name(this->getTarget() + "_shrubbery");
	std::string		tree;

	this->verify_execution_requirements(executor);
	file.open(file_name.c_str(), std::ios::trunc);
	file << ShrubberyCreationForm::getTree();
	file.close();
}
