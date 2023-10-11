#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	ShrubberyCreationForm	shrub("home");

	shrub.execute(Bureaucrat());
	return (0);
}
