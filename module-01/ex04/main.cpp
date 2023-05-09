#include <iostream>
#include <fstream>

void	error(std::string message) {
	std::cout << message << std::endl;
	exit(1);
}

std::string	replace(std::string line, size_t pos, int len, std::string s2) {
	line.erase (pos, len);
	line.insert (pos, s2);
	return line;
}

int main(int argc, char **argv){
	if (argc != 4) { error("Usage: ./main <filename> <s1> <s2>"); }

	std::string filename = argv[1];

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream file(filename);
	if (!file.is_open()) { error("Error: file not found"); }
	std::ofstream replaced_file(filename + ".replace");

	std::string line;

	for (; std::getline(file, line) ;) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = replace(line, pos, s1.length(), s2);
			pos += s2.length();
		}
		replaced_file << line << std::endl;
	}
	file.close();
	return 0;
}
