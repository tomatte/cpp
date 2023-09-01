#include <iostream>
#include <string>

class Student {
	int age;
	public:
		Student(void);
		~Student(void);
		int	get_age(void) const;
		static int constructions;
};

int Student::constructions = 0;

Student::Student(void) : age(81) {
	std::cout << "Constructor called!" << std::endl;
	Student::constructions++;
	return ;
}

Student::~Student(void) {
	std::cout << "Destructor called!" << std::endl;
	return ;
}

int Student::get_age(void) const {
	return this->age;
}

int	main(void) {
	Student a;
	Student *students = new Student[20];

	std::cout << a.get_age() << std::endl;
	delete [] students;
	std::cout << "Constructions: " << Student::constructions << std::endl;
	return (0);
}
