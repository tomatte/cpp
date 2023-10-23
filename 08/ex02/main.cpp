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

void	my_tests(void)
{
	MutantStack<int>	mutant;

	std::cout << "\n-------- my_simple_test --------" << std::endl;
	mutant.push(1);
	mutant.push(5);
	mutant.push(10);
	MutantStack<int>	copy(mutant);
	MutantStack<int> const &	const_ref = copy;
	std::cout << "size: " << mutant.size() << std::endl;

	MutantStack<int>::const_reverse_iterator	rit;
	rit = mutant.rbegin();
	std::cout << "first const_reverse_iterator item: " << *rit << std::endl;
	std::cout << "\nusing const reference to pass rerse iterator to for_each and a print func: " << std::endl;

	std::for_each(const_ref.rbegin(), const_ref.rend(), print<int>);
	std::cout << "\nfind(5): " << *(std::find(mutant.begin(), mutant.end(), 5)) << std::endl;  
}

int	main(void)
{
	mutant_subject_test();
	list_subject_test();
	my_tests();
	return (0);
}