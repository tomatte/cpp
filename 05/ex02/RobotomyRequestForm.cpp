#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include "ColorOut.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
AForm("robotomy request", 72, 45)
{
	this->setTarget("none");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("robotomy request", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : 
AForm(rhs)
{
	this->setTarget(rhs.getTarget());
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	AForm::operator=(rhs);
	this->setTarget(rhs.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	clock_t	start_time;
	int	seed;
	int	aux;

	this->verify_execution_requirements(executor);
	start_time = clock();
	ColorOut::yellow << "[!] Vrrrrrrrmmmmmm";
	aux = 0;
	while (clock() < start_time + 1800000)
	{
		if (aux < clock())
		{
			ColorOut::yellow << "." << std::flush;
			aux += 200000;
		}
	}
	std::cout << std::endl;
	seed = time(NULL) + clock();
	srand(seed);
	if (rand() % 2)
		ColorOut::green_b << this->getTarget()
			<< " has been robotomized successfully!!!\n";
	else
		ColorOut::red << this->getTarget() << " robotomization failed X_x\n";
}
