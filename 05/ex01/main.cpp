#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>
#include "Form.hpp"


int main(void)
{
	Form	form("form_01", 10, 20);

	std::cout << form;
	return (0);
}
