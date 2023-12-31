#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"
#include <cstdlib>

std::vector<int>	generate_list(int qty, int largest)
{
	std::vector<int>	list;
	const int	seed = time(NULL);
	srand(seed);
	for (int i = 0; i < qty; i++)
		list.push_back(rand() % largest);
	return (list);
}

void	subject_test(void)
{
	std::cout << "---------- Subject Test ----------" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	my_test_one(void)
{
	Span	span(51);

	std::cout << "\n********** my_test_one **********\n" << std::endl;
	std::vector<int>	aux = generate_list(30, 1000);
	std::vector<int>	aux2 = generate_list(30, 1000);
	span.addNumbersBulk(aux.begin(), aux.end());
	span.results();
	try
	{
		span.addNumbersBulk(aux2.begin(), aux2.end());
		std::cout << "Bulk added succesfully" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "addNumbersBulk failed: " << e.what() << std::endl;
	}
}

void	ten_thousand_test(void)
{
	Span				big_span(10000);
	std::vector<int>	list = generate_list(10000, 4000000000);
	
	big_span.addNumbersBulk(list.begin(), list.end());
	std::cout << "\n---------- TEN THOUSAND TEST ----------" << std::endl;
	std::cout << big_span << std::endl;
	std::cout << "\nShortest span: " << big_span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << big_span.longestSpan() << std::endl;
}

int	main(void)
{
	subject_test();
	my_test_one();
	//ten_thousand_test();
	return (0);
}