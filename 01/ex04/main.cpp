#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#define	BUFF_SIZE 1025
#define	OLD 2
#define	NEW 3

void	some_validations(int argc, char *argv[]) {
	std::string	s;

	if (argc != 4) {
		std::cout << "Wrong number of arguments, expects 3\n";
		std::cout << "Program finished.\n";
		std::exit(1);
	}
	s = argv[OLD];
	if (s.empty()) {
		std::cout << "Error: The string to be replaced can't be empty: exited\n";
		exit(2);
	}
}

void	open_file(std::ifstream & file, char const *file_name) {
	file.open(file_name);
	if (!file == false)
		return ;
	std::cout << "Error: failed to open " << file_name << ": exited\n";
	exit(1);
}

void	open_file(std::ofstream & outfile, char const *file_name) {
	std::string	replace_file;

	replace_file = std::string(file_name) + ".replace";
	outfile.open(replace_file.c_str(), std::ios::trunc);
	if (!outfile == false)
		return ;
	std::cout << "Error: failed to open " << file_name << ": exited\n";
	exit(1);
}

void	search_and_replace(std::string & line, char **argv) {
	size_t	i;
	std::string	modified;
	std::string	s_old(argv[OLD]);
	std::string	s_new(argv[NEW]);

	while (1) {
		if (line.empty())
			break ;
		i = line.find(argv[OLD]);
		if (i == line.npos)
			break ;
		modified += (line.substr(0, i) + s_new);
		line = line.substr(i + s_old.length(), line.length());
	}
	line = modified + line;
}

void	operation(std::ifstream & in, std::ofstream & out, char **argv) {
	char	buffer[1024];
	std::string	line;

	while (in.eof() == false) {
		in.getline(buffer, BUFF_SIZE - 1);
		line = buffer;
		if (in.eof() == false)
			line += "\n";
		search_and_replace(line, argv);
		out.write(line.c_str(), line.length());
	}
}

int	main(int argc, char *argv[]) {
	std::ifstream	infile;
	std::ofstream	outfile;

	some_validations(argc, argv);
	open_file(infile, argv[1]);
	open_file(outfile, argv[1]);
	operation(infile, outfile, argv);
	infile.close();
	outfile.close();
	return (0);
}
