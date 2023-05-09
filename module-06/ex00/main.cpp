#include <iostream>
#include <iomanip>
#include "ScalarString.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;

	ScalarString scalarString(argv[1]);
	try {
		char c = static_cast<char>(scalarString);
		std::cout << "char : '" << c << "'\n";
	}
	catch(const std::exception& e) {
		std::cout << "char : " << e.what() << '\n';
	}

	try {
	int i = static_cast<int>(scalarString);
	std::cout << "int : " << i << "\n";
	}
	catch(const std::exception& e) {
	std::cout << "int : " << e.what() << '\n';
	}

	std::cout << std::setprecision(1) << std::fixed;
	try{
	float f = static_cast<float>(scalarString);
	std::cout << "float : " << f << "f\n";
	}
	catch(const std::exception& e) {
	std::cout << "float : " << e.what() << "\n";
	}

	try{
	double d = static_cast<double>(scalarString);
	std::cout << "double : " << d << "\n";
	}
	catch(const std::exception& e){
	std::cout << "double : " << e.what() << "\n";
	}
}
