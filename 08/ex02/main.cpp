#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <algorithm>
#include <deque>
#include <list>

template <typename T>
void	print(T content)
{
	std::cout << content << std::endl;
}

void	mutant_subject_test(void)
{
	MutantStack<int> mstack;

	std::cout << "\n---------- mutant subject test ----------" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void	list_subject_test(void)
{
	std::list<int> mstack;

	std::cout << "\n---------- list subject test ----------" << std::endl;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
}

int	main(void)
{
	MutantStack<int>	mutant;

	MutantStack<int>::iterator	it;

	mutant.push(1);
	mutant.push(5);
	mutant.push(10);
	for (it = mutant.begin(); it != mutant.end(); it++)
		std::cout << "it: " << *it << std::endl;
	//std::for_each(mutant.begin(), mutant.end(), print<int>);
	mutant_subject_test();
	list_subject_test();
	return (0);
}