#include "Harl.hpp"

void    error(std::string msg) {
	std::cout << msg << std::endl;
	exit(1);
}

int main( int argc, char **argv ) {
	if (argc != 2) { error("Usage: ./HarlFilter <level>"); }

	Harl harl;
	std::string level = argv[1];
	harl.complain(level);
	return 0;
}