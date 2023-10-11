#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>


int main(void)
{
	Bureaucrat	*bureaucrat = NULL;

	///////////////////////////////////////////////////////////
	std::cout << "--------------- Test 1 ---------------" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Adan", 156);
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch(std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////
	std::cout << "\n--------------- Test 2 ---------------\n";
	try
	{
		bureaucrat = new Bureaucrat("Josh", 1);
		std::cout << *bureaucrat << std::endl;		
	}
	catch(std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		bureaucrat->increment_grade();
		std::cout << "Josh was incremented" << std::endl;
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch(std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		delete bureaucrat;
	}

	///////////////////////////////////////////////////////////
	std::cout << "\n--------------- Test 3 ---------------\n";
	try
	{
		bureaucrat = new Bureaucrat("Blue", -10);
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << "The minimum grade is 150." << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << "The maximum grade is 1." << std::endl;
	}
	return (0);
}
