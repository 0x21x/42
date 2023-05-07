#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {

	// Vector
	try {
		std::vector<int> vec;
		std::vector<int>::iterator pos;
		for (int i = 0; i < 50; i++)
			vec.push_back(i);
		pos = easyfind(vec, 42);
		std::cout << "The value is found in container. ;)" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// List
	try {
		std::list<int> lst;
		std::list<int>::iterator posLst;
		for (int i = 0; i < 50; i++)
			lst.push_back(i);
		posLst = easyfind(lst, 42);
		std::cout << "The value is found in container. ;)" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

