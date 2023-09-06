#include <string>
#include <iostream>

void    scream(std::string & str) {

	for (int i = 0; i < (int) str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
	std::cout << str;
}

void	feed_back_noise(void) {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

void    print_args(int argc, const char **argv) {
	std::string	str;
	bool		is_empty;

	is_empty = true;
	if (argc == 1)
		feed_back_noise();
	for (int i = 1; i < argc; i++) {
		str = argv[i];
		if (i > 1 && is_empty == false && str != "")
			std::cout << " ";
		if (str != "")
			is_empty = false;
		if (str != "")
			scream(str);
	}
	if (is_empty == true && argc > 1)
		feed_back_noise();
	std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
	print_args(argc, argv);
	return (0);
}
