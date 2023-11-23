#ifndef DEBUG_H
# define DEBUG_H
# include <iostream>
# include <algorithm>

template<typename T>
void	print_item(T & item)
{
	std::cout << " " << item << " ";
}

template<typename Container>
void	print_items(Container & c)
{
	std::cout << "* ";
	std::for_each(c.begin(), c.end(), print_item<typename Container::value_type>);
	std::cout << " *" << std::endl;
}

#endif