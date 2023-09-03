#include <string>
#include <iostream>

using namespace std;

int	main(void) {
	int		number = 42;
	int&	num_ref = number;
	int		*num_ptr;

	num_ptr = &number;
	cout << "Let's go!" << endl;
	cout << "number: " << number << endl;
	cout << "num_ref: " << num_ref << endl;
	cout << "num_ptr: " << num_ptr << endl;
	cout << "*num_ptr: " << *num_ptr << endl;

	num_ref = 43;
	cout << "\nLet's go!" << endl;
	cout << "number: " << number << endl;
	cout << "num_ref: " << num_ref << endl;
	cout << "num_ptr: " << num_ptr << endl;
	cout << "*num_ptr: " << *num_ptr << endl;
	cout << "&num_ref: " << &num_ref << endl;
	cout << "*(&num_ref): " << *(&num_ref) << endl;
	return (0);
}