#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	Bureaucrat				josh("Josh", 100);
	ShrubberyCreationForm	shrub("home");

	/* Fail try  */
	try
	{
		shrub.execute(josh);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	/* Successful try  */
	try
	{
		shrub.beSigned(josh);
		shrub.execute(josh);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
