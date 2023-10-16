#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "ColorOut.hpp"


AForm	*Intern::createShrubberyRequest(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::createRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*(*Intern::createFormFunctions[3])(std::string) = {
		Intern::createShrubberyRequest,
		Intern::createRobotomyRequest,
		Intern::createPresidentialPardon
	};

std::string	Intern::formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};


Intern::Intern(void)
{
}

Intern::Intern(Intern const & rhs)
{
	(void) rhs;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void) rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (Intern::formNames[i] == form)
		{
			ColorOut::green << "Intern creates " << form << "\n";
			return (Intern::createFormFunctions[i](target));
		}
	}
	ColorOut::yellow << "! ";
	std::cout << "Error: '" << form << "' form doesn't exist.\n";
	return (NULL);
}
