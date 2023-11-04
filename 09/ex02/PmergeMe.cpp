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
void	PmergeMe::merge(t_vector & left, t_vector & right, t_vector & c)
{
	typename t_vector::iterator	left_it = left.begin();
	typename t_vector::iterator	right_it = right.begin();
	typename t_vector::iterator	main_it = c.begin();

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

void	PmergeMe::merge_sort(t_vector & c)
{
	if (c.size() <= 1)
		return ;

	const int leftSize = c.size() / 2;
	const int rightSize = c.size() - leftSize;

	t_vector leftVector(leftSize);
	t_vector rightVector(rightSize);

	std::copy(c.begin(), c.begin() + leftSize, leftVector.begin());
	std::copy(c.begin() + leftSize, c.end(), rightVector.begin());
	merge_sort(leftVector);
	merge_sort(rightVector);
	merge(leftVector, rightVector, c);
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
		merge_sort(_vector);
		merge_sort(_deque);
		std::cout << "\nEND\nlist: "; print_items(_deque);
		std::cout << "vector: "; print_items(_vector);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
