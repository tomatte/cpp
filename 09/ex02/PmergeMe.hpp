#ifndef PMERGEME_H
# define PMERGEME_H
# include <vector>
# include <list>
# include <algorithm>
# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include <deque>

# define t_vector std::vector<int>
# define t_deque std::deque<int>

class PmergeMe
{
	private:
		t_vector	_vector;
		t_deque		_deque;
		
		static void	merge(t_vector & left, t_vector & right, t_vector & c);
		static void	merge(t_deque & left, t_deque & right, t_deque & c);

		static void	merge_sort(t_vector & c);
		static void	merge_sort(t_deque & c);

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