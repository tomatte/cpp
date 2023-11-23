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
# include <map>
# include <time.h>

typedef std::deque<int> t_deque;
typedef std::deque<t_deque> t_deques;
typedef typename std::list<int> t_list;
typedef std::list<t_list> t_lists;

class PmergeMe
{
	private:
		t_deque		_deque;
		t_list		_list;

		double _deque_time;
		double _list_time;

		int & list(int index);
		t_list::iterator iterator(t_list & c, int index);
		static int & list(t_list & c, int index);
		
		static void	merge(t_deques & left, t_deques & right, t_deques & c);
		static void	merge(t_list & left, t_list & right, t_list & c);

		static void	merge_sort(t_deques & c);
		static void	merge_sort(t_list & c);

		static void sort_two(t_deque & c);
		void sort_two(void);

		static void	create_main_and_pend(t_deque & c);
		void	create_main_and_pend(t_list & c);

		void sort_deque(void);
		void sort_list(void);

		static int	str_to_int(const char *str);

		static int	pop_back(t_deque & c);
		static int	pop_front(t_deque & c);
		static int	pop_back(t_list & c);
		static int	pop_front(t_list & c);

		static void	insert(t_deque & c, int n);
		void	insert(t_list & c, int n);
		static void	find_place(t_deque & c, int target, int start, int end);
		void	find_place(t_list & c, int target, int start, int end);
		
		static int		jacobsthal(unsigned int index);
		static t_deque 	create_indexes(t_deque & pend);
		static t_list 	create_indexes(t_list & pend);
		static bool		find(t_deque & c, int n);
		static bool		find(t_list & c, int n);

		static void		binary_insert_pend_elements(
				t_deque & main,
				t_deque & pend, 
				t_deque & indexes
			);
		void		binary_insert_pend_elements(
				t_list & main,
				t_list & pend, 
				t_list & indexes
			);


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