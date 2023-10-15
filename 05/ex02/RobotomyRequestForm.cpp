#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include "ColorOut.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
AForm("RobotomyRequestForm", 72, 45), _target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : 
AForm(rhs), _target(rhs._target)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	clock_t	start_time;
	int	seed;

	this->verify_execution_requirements(executor);
	start_time = clock();
	ColorOut::yellow << "[!] Vrrrrrrrmmmmmm...   " << std::endl;
	seed = time(NULL) + start_time;
	srand(seed);
	while (clock() < start_time + 900000);
	if (rand() % 2)
		ColorOut::green_b << executor.getName() << " has been robotomized successfully!!!\n";
	else
		ColorOut::red << executor.getName() << " robotomization failed X_x\n";
}
