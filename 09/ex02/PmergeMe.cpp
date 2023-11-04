#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(PmergeMe const & rhs)
{
	(void)rhs;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "pmerge destructed\n";
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	(void)rhs;
	return (*this);
}
void	PmergeMe::merge(t_vector & c)
{

}

void	PmergeMe::merge(t_list & c)
{

}

void	PmergeMe::merge_sort(t_vector & c)
{

}

void	PmergeMe::merge_sort(t_list & c)
{

}

void	PmergeMe::sort(void)
{
	
}

void	PmergeMe::convert(int argc, char *argv[])
{
	
}