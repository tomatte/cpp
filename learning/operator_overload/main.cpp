#include <string>
#include <iostream>

using namespace std;

class Sample {
	public:
		Sample(void);
		Sample(int n);
		Sample(Sample const & src);
		~Sample(void);
		int	get_number(void) const;
		Sample &	operator=(Sample const & rhs);

	private:
		int _number;
};

Sample &	Sample::operator=(Sample const & rhs) {
	this->_number = rhs._number;
	cout << "Operator overload called!\n";
	return (*this);
}

Sample::Sample(void) : _number(0) {
	cout << "Default constructor called!\n";
}
Sample::Sample(int n) : _number(n) {
	cout << "Parameter constructor called!\n";
}
Sample::Sample(Sample const & rhs) {
	this->_number = rhs._number;
	cout << "Copy constructor called!\n";
}

Sample::~Sample(void) {
	cout << "Destructor called!\n";
}

int	Sample::get_number(void) const {
	return this->_number;
}

int	main(void) {
	Sample	sample1;
	Sample	sample2(9);
	Sample	sample3(sample1);

	cout << "\nSample1: " << sample1.get_number() << endl;
	cout << "Sample2: " << sample2.get_number() << endl;
	cout << "Sample3: " << sample3.get_number() << "\n\n";

	sample1 = sample3 = sample2;

	cout << "\nSample1: " << sample1.get_number() << endl;
	cout << "Sample2: " << sample2.get_number() << endl;
	cout << "Sample3: " << sample3.get_number() << "\n\n";
	return (0);
}