#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define BLUE "\033[0;34m"
# define NO_COLOR "\033[0m"

static void	set_color(std::string color)
{
	std::cout << color;
}

int	main(void)
{
	const	int		N = 10;
	const	AAnimal	*animals[N];
	//const	AAnimal	concrete;  //can't  be done because it's an abstract class

	for (int i = 0; i < N / 2; i++)
		animals[i] = new Cat();

	for (int i = N / 2; i < N; i++)
		animals[i] = new Dog();

	set_color(BLUE);
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();
	set_color(NO_COLOR);

	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "---------- More Tests ----------" << std::endl;
	Cat	cat;
	Cat	copy_cat;

	cat.set_idea(0, "find a cake");
	copy_cat = cat;
	copy_cat.set_idea(0, "bite a human");
	set_color(BLUE);
	std::cout << "Cat: " << cat.get_idea(0) << std::endl;
	std::cout << "CopyCat: " << copy_cat.get_idea(0) << std::endl;
	set_color(NO_COLOR);
	return (0);
}
