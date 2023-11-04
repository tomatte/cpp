#ifndef PMERGEME_H
# define PMERGEME_H
# include <vector>
# include <list>
# include <algorithm>
# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>

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

		static int	str_to_int(const char *str);

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const & rhs);
		~PmergeMe(void);
		
		PmergeMe & operator=(PmergeMe const & rhs);

		//get_list
		//get_vector

		void	sort(int argc, char *argv[]);
		void	init(int argc, char *argv[]);
};

#endif