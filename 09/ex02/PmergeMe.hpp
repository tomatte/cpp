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

typedef std::deque<int> t_deque;
typedef std::deque<t_deque> t_deques;
typedef typename std::list<int> t_list;
typedef std::list<t_list> t_lists;

class PmergeMe
{
	private:
		t_deque		_deque;
		t_list		_list;
		
		static void	merge(t_deques & left, t_deques & right, t_deques & c);

		static void	merge_sort(t_deques & c);

		static void	create_main_and_pend(t_deque & c);

		static int	str_to_int(const char *str);

		static int	pop_back(t_deque & c);
		static int	pop_front(t_deque & c);

		static void	insert(t_deque & c, int n);
		static void	find_place(t_deque & c, int target, int start, int end);

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