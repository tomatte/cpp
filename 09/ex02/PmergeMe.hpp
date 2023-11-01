#ifndef PMERGEME_H
# define PMERGEME_H

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const & rhs);
		~PmergeMe(void);
		
		PmergeMe & operator=(PmergeMe const & rhs);
};

#endif