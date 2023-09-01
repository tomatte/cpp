#include <string>
#include <iostream>

void    scream(const char *s) {
	std::string str = s;
	for (int i = 0; i < (int) str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
	std::cout << str;
}

void    print_args(int argc, const char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		if (i > 1)
			std::cout << " ";
		scream(argv[i]);
	}
	std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
	print_args(argc, argv);
	return (0);
}
