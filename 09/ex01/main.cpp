#include <iostream>
#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}

	RPN	rpn;

	try { rpn.operation(argv[1]); }
	catch (std::runtime_error & e) { std::cout << e.what() << std::endl; }
	return (0);
}