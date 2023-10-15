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
	Bureaucrat				josh("Josh", 1);
	AForm	*shrub = new ShrubberyCreationForm("home");
	AForm	*robotomy = new RobotomyRequestForm("Josh");

	std::cout << "----------- Shrubbery Test -----------\n";
	/* Fail  */
	josh.executeForm(*shrub);

	/* Success  */
	shrub->beSigned(josh);
	josh.executeForm(*shrub);

	std::cout << "\n----------- Robotomy Test -----------\n";
	josh.executeForm(*robotomy);
	robotomy->beSigned(josh);
	josh.executeForm(*robotomy);
	return (0);
}
