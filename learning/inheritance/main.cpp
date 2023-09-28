#include <iostream>

class Human {
	protected:
		std::string	name;
		int			age;
	public:
		Human(std::string name, int age) {
			this->name = name;
			this->age = age;
		}
		std::string	get_name(void) const {
			return this->name;
		}
		int	get_age(void) const {
			return this->age;
		}
};

class Hero : public Human {
	public:
		Hero(std::string name, int age);
		void	fly(void) const {
			std::cout << "Flying..." << std::endl;
		}
};

Hero::Hero(std::string name, int age) : Human(name, age) {}

void	print_human(Human & human) {
	std::cout << "Human name: " << human.get_name() << std::endl;
	std::cout << "Human age:  " << human.get_age() << std::endl;
}

void	print_hero(Hero & hero) {
	std::cout << "Hero name: " << hero.get_name() << std::endl;
	std::cout << "Hero age:  " << hero.get_age() << std::endl;
}

int	main(void)
{
	Human	a("Julius", 40);
	Hero	hero("John", 28);

	print_human(a);
	print_hero(hero);
	return (0);
}
