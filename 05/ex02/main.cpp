#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>


int main(void)
{
	Bureaucrat				josh("Josh", 137);
	Bureaucrat				mary("Mary", 45);
	Bureaucrat				ariel("Ariel", 1);
	AForm	*shrub = new ShrubberyCreationForm("home");
	AForm	*robotomy = new RobotomyRequestForm("Josh");

	std::cout << "----------- Shrubbery Test -----------\n";
	josh.signForm(*shrub);
	josh.executeForm(*shrub);

	std::cout << "\n----------- Robotomy Test -----------\n";
	josh.signForm(*robotomy);
	josh.executeForm(*robotomy);
	std::cout << std::endl;
	mary.signForm(*robotomy);
	mary.executeForm(*robotomy);


	return (0);
}
