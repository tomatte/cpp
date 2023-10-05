#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const int		N = 10;
	const Animal	*animals[N];

	//NEED TO TEST IF COPIES ARE DEEP OR SHALLOW, IT NEEDS TO BE DEEP

	for (int i = 0; i < N / 2; i++)
		animals[i] = new Cat();

	for (int i = N / 2; i < N; i++)
		animals[i] = new Dog();

	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		delete animals[i];
	return (0);
}
