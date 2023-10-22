#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <algorithm>

template <typename T>
void	print(T content)
{
	std::cout << content << std::endl;
}

int	main(void)
{
	MutantStack<int>	mutant;

	mutant.push(1);
	mutant.push(5);
	mutant.push(10);
	std::for_each(mutant.begin(), mutant.end(), print<int>);
	return (0);
}