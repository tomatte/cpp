#include "PmergeMe.hpp"
# include "debug.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(PmergeMe const & rhs)
{
	(void)rhs;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	(void)rhs;
	return (*this);
}
void	PmergeMe::merge(t_deques & left, t_deques & right, t_deques & c)
{
	typename t_deques::iterator	left_it = left.begin();
	typename t_deques::iterator	right_it = right.begin();
	typename t_deques::iterator	main_it = c.begin();

	while (left_it != left.end() && right_it != right.end())
	{
		if (*right_it < *left_it)
		{
			*main_it = *right_it;
			right_it++;
		}
		else
		{
			*main_it = *left_it;
			left_it++;
		}
		main_it++;
	}

	while (left_it < left.end())
	{
		*main_it = *left_it;
		left_it++;
		main_it++;
	}

	while (right_it < right.end())
	{
		*main_it = *right_it;
		right_it++;
		main_it++;
	}
}

void	PmergeMe::merge_sort(t_deques & c)
{
	if (c.size() <= 1)
		return ;

	const int leftSize = c.size() / 2;
	const int rightSize = c.size() - leftSize;

	t_deques leftVector(leftSize);
	t_deques rightVector(rightSize);

	std::copy(c.begin(), c.begin() + leftSize, leftVector.begin());
	std::copy(c.begin() + leftSize, c.end(), rightVector.begin());
	merge_sort(leftVector);
	merge_sort(rightVector);
	merge(leftVector, rightVector, c);
}

/* 
	if array is odd, store the last element somewhere
	criar n/2 arrays of 2 items
	order each array to start with the highest value
	order the arrays based on the first item 
	(how to order them? should I use binary insert here? should I use merge sort? maybe)
 */

int	PmergeMe::pop_back(t_deque & c)
{
	const int num = c.back();
	c.pop_back();
	return (num);
}

int	PmergeMe::pop_front(t_deque & c)
{
	const int num = c.front();
	c.pop_front();
	return (num);
}

void	PmergeMe::find_place(t_deque & c, int target, int start, int end)
{
	if (start >= end)
	{
		std::cout << "index: " << (end + 1) << std::endl;
		return ;
	}
	if (end <= start)
	{
		std::cout << "index: " << (start + 1) << std::endl;
		return ;
	}

	const int middle = (start + end) / 2;

	if (c[middle] == target)
	{
		std::cout << "index: " << (middle + 1) << std::endl;
		return ;
	}

	if (middle != end && c[middle] < target && c[middle + 1] > target)
	{
		std::cout << "index: " << (middle + 1) << std::endl;
		return ;
	}

	if (middle != start && c[middle - 1] < target && c[middle] > target)
	{
		std::cout << "index: " << middle << std::endl;
		return ;
	}

	if (c[middle] < target)
		return (find_place(c, target, middle + 1, end));
	else
		return (find_place(c, target, start, middle - 1));
}

void	PmergeMe::insert(t_deque & c, int n)
{
	find_place(c, n, 0, c.size() - 1);
}

void	PmergeMe::create_main_and_pend(t_deque & c)
{
	int struggler;

	//create n/2 vectors of 2 elements
	if (c.size() % 2 != 0)
		struggler = c.back();
	const int len = c.size() / 2;
	t_deques	vec_list;
	for (int i = 0; i < len * 2; i += 2)
	{
		t_deque item;
		if (c[i] >= c[i + 1])
		{
			item.push_back(c[i]);
			item.push_back(c[i + 1]);
		}
		else
		{
			item.push_back(c[i + 1]);
			item.push_back(c[i]);
		}
		vec_list.push_back(item);
	}

	//merge sort list
	merge_sort(vec_list);

	t_deque	main;
	t_deque	pend;
	for (int i = 0; i < vec_list.size(); i++)
	{
		main.push_back(vec_list[i][0]);
		pend.push_back(vec_list[i][1]);
	}

	for (int i = 0; i < vec_list.size(); i++)
	{
		print_items(vec_list[i]);
	}

	main.push_front(pop_front(pend));
	std::cout << "main: "; print_items(main);
	std::cout << "pend: "; print_items(pend);
	insert(main, 16);
	insert(main, 12);
	insert(main, 11);
	insert(main, 7);
	insert(main, 4);
	insert(main, 2);
}

int	PmergeMe::str_to_int(const char *str)
{
	std::stringstream	ss(str);
	int n;
	ss >> n;
	if (ss.fail())
		throw std::runtime_error("invalid number found");
	return (n);
}

void	PmergeMe::init(int argc, char *argv[])
{
	if (argc <= 1)
		throw std::runtime_error("too few args");
	for (int i = 1; i < argc; i++)
	{
		const int number = str_to_int(argv[i]);
		_deque.push_back(number);
		_list.push_back(number);
	}
}

void	PmergeMe::sort(int argc, char *argv[])
{
	try
	{
		init(argc, argv);
		// merge_sort(_vector);
		// merge_sort(_deque);
		create_main_and_pend(_deque);
		std::cout << "\nvector: "; print_items(_deque);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* 
 1 2 3 4 5 6 7 8 9 10
 
  */