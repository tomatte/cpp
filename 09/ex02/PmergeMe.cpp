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
void	PmergeMe::merge(t_vectors & left, t_vectors & right, t_vectors & c)
{
	typename t_vectors::iterator	left_it = left.begin();
	typename t_vectors::iterator	right_it = right.begin();
	typename t_vectors::iterator	main_it = c.begin();

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

void	PmergeMe::merge_sort(t_vectors & c)
{
	if (c.size() <= 1)
		return ;

	const int leftSize = c.size() / 2;
	const int rightSize = c.size() - leftSize;

	t_vectors leftVector(leftSize);
	t_vectors rightVector(rightSize);

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

void	PmergeMe::create_main_and_pend(t_vector & c)
{
	int struggler;

	//create n/2 vectors of 2 elements
	if (c.size() % 2 != 0)
		struggler = c.back();
	const int len = c.size() / 2;
	std::vector<t_vector>	vec_list;
	vec_list.reserve(len);
	for (int i = 0; i < len * 2; i += 2)
	{
		t_vector item;
		item.reserve(2);
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

	t_vector	main;
	t_vector	pend;
	for (int i = 0; i < vec_list.size(); i++)
	{
		main.push_back(vec_list[i][0]);
		pend.push_back(vec_list[i][1]);
	}

	for (int i = 0; i < vec_list.size(); i++)
	{
		print_items(vec_list[i]);
	}

	std::cout << "main: "; print_items(main);
	std::cout << "pend: "; print_items(pend);
}

void	PmergeMe::merge(t_deque & left, t_deque & right, t_deque & c)
{
	typename t_deque::iterator	left_it = left.begin();
	typename t_deque::iterator	right_it = right.begin();
	typename t_deque::iterator	main_it = c.begin();

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

void	PmergeMe::merge_sort(t_deque & c)
{
	if (c.size() <= 1)
		return ;

	const int leftSize = c.size() / 2;
	const int rightSize = c.size() - leftSize;

	t_deque leftVector(leftSize);
	t_deque rightVector(rightSize);

	std::copy(c.begin(), c.begin() + leftSize, leftVector.begin());
	std::copy(c.begin() + leftSize, c.end(), rightVector.begin());
	merge_sort(leftVector);
	merge_sort(rightVector);
	merge(leftVector, rightVector, c);
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
		_vector.push_back(number);
	}
}

void	PmergeMe::sort(int argc, char *argv[])
{
	try
	{
		init(argc, argv);
		// merge_sort(_vector);
		// merge_sort(_deque);
		create_main_and_pend(_vector);
		std::cout << "\nvector: "; print_items(_vector);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
