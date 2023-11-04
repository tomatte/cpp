#ifndef PMERGEME_H
# define PMERGEME_H
# include <vector>
# include <list>
# include <algorithm>
# include <iostream>
# include <string>

# define t_vector std::vector<int>
# define t_list std::list<int>

class PmergeMe
{
	private:
		t_vector	_vector;
		t_list		_list;
		
		static void	merge(t_vector & c);
		static void	merge(t_list & c);

		static void	merge_sort(t_vector & c);
		static void	merge_sort(t_list & c);

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const & rhs);
		~PmergeMe(void);
		
		PmergeMe & operator=(PmergeMe const & rhs);

		//get_list
		//get_vector

		void	sort(void);
		static void	convert(int argc, char *argv[]);
};

#endif