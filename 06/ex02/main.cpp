#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <stdexcept>

Base	*generate_a(void) { return (new A); }
Base	*generate_b(void) { return (new B); }
Base	*generate_c(void) { return (new C); }

Base * generate(void)
{
	static Base* (*generators[3])(void) = {generate_a, generate_b, generate_c};

	const size_t seed = time(NULL) + clock();
	srand(seed);
	return (generators[rand() % 3]());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C pointer" << std::endl;
	else
		std::cout << "pointer error" << std::endl;

}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A reference" << std::endl;
	}
	catch(std::exception & e)
	{
		(void) e;
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "B reference" << std::endl;
		}
		catch(std::exception & e)
		{
			(void) e;
			try
			{
				dynamic_cast<C &>(p);
				std::cout << "C reference" << std::endl;
			}
			catch(std::exception & e)
			{
				(void) e;
				std::cout << "reference error" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base	&random_class_reference = *(generate());
	Base	*random_class_pointer;

	random_class_pointer = generate();
	identify(random_class_pointer);
	identify(random_class_reference);
	delete random_class_pointer;
	delete &random_class_reference;
	return (0);
}
