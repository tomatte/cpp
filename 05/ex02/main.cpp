#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat				josh("Josh", 137);
	Bureaucrat				mary("Mary", 45);
	Bureaucrat				ariel("Ariel", 1);
	AForm	*shrub = new ShrubberyCreationForm("home");
	AForm	*robotomy = new RobotomyRequestForm("Josh");
	AForm	*pardon = new PresidentialPardonForm("Mary");

	std::cout << "----------- Shrubbery Test -----------\n";
	josh.signForm(*shrub);
	josh.executeForm(*shrub);

	std::cout << "\n----------- Robotomy Test -----------\n";
	josh.signForm(*robotomy);
	josh.executeForm(*robotomy);
	std::cout << std::endl;
	mary.signForm(*robotomy);
	mary.executeForm(*robotomy);

	std::cout << "\n----------- Presidential Pardon Test -----------\n";
	ariel.signForm(*pardon);
	ariel.executeForm(*pardon);
	return (0);
}
