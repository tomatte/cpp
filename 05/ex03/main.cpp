#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm	*form;
	Intern	intern;
	Bureaucrat	james("James", 45);

	form = intern.makeForm("helicopter request", "Willian");

	std::cout << "\n---------- Presidential Pardon Form ----------\n"; 
	form = intern.makeForm("presidential pardon", "James");
	if (form)
	{
		james.signForm(*form);
		james.executeForm(*form);
		delete form;
	}

	std::cout << "\n---------- Shrubbery Creation Form ----------\n"; 
	form = intern.makeForm("shrubbery creation", "hotel");
	if (form)
	{
		james.signForm(*form);
		james.executeForm(*form);
		delete form;
	}

	std::cout << "\n---------- Robotomy Request Form ----------\n"; 
	form = intern.makeForm("robotomy request", "Willian");
	if (form)
	{
		james.signForm(*form);
		james.executeForm(*form);
		delete form;
	}
	return (0);
}
