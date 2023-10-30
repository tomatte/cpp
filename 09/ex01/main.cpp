#include <iostream>

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}

	return (0);
}