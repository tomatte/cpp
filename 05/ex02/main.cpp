#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>
#include "AForm.hpp"


int main(void)
{
	AForm		form("form_01", 10, 20);
	Bureaucrat	josh("Josh", 5);
	Bureaucrat	ada("Ada", 15);

	ada.signForm(form);
	josh.signForm(form);

	std::cout << std::endl;
	std::cout << form;
	return (0);
}
