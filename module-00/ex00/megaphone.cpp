#include <iostream>
#include <cstring>

int	main(int argc, char **argv) {
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}
	
	for (int i = 1; argv[i]; i++) {
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>( std::toupper(argv[i][j]) );
	};
	std::cout << "\n";
	return 0;
}