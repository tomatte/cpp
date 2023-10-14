#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	Bureaucrat				josh("Josh", 100);
	ShrubberyCreationForm	shrub("home");

	/* Fail  */
	josh.executeForm(shrub);

	/* Success  */
	shrub.beSigned(josh);
	josh.executeForm(shrub);

	return (0);
}
