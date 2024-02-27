#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "Wrong numbers arguments." << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		rpn.parse(av[1]);
		int result = rpn.calculate();
		std::cout << result << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}