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
	AForm	*shrub2 = new ShrubberyCreationForm("farm");
	AForm	*robotomy = new RobotomyRequestForm("Josh");
	AForm	*pardon = new PresidentialPardonForm("Mary");

	std::cout << "----------- Shrubbery Test -----------\n";
	josh.signForm(*shrub);
	josh.executeForm(*shrub);

	std::cout << "\n----------- Robotomy Fail -----------\n";
	josh.signForm(*robotomy);
	josh.executeForm(*robotomy);


	std::cout << "\n----------- Presidential Pardon Test -----------\n";
	ariel.signForm(*shrub2);
	ariel.executeForm(*shrub2);
	ariel.signForm(*pardon);
	mary.executeForm(*pardon);
	ariel.executeForm(*pardon);

	std::cout << "\n----------- Robotomy Success -----------\n";
	mary.signForm(*robotomy);
	mary.executeForm(*robotomy);

	delete shrub;
	delete robotomy;
	delete pardon;
	delete shrub2;
	return (0);
}
