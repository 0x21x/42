#include "Span.hpp"

int main() {
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span spa = Span(10);
		std::vector<int> tmp;
		for (int i = 0; i < 9; i++)
			tmp.push_back(i);
		spa.addNumber(111);
		spa.addRange(tmp.begin(), tmp.end());
		std::cout << spa.shortestSpan() << std::endl;
		std::cout << spa.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::srand(std::time(nullptr));
		Span g1 = Span(111111);
		for (int i = 0; i < 111111; i++)
			g1.addNumber(std::rand());
		std::cout << g1.shortestSpan() << std::endl;
		std::cout << g1.longestSpan() << std::endl;
		g1.addNumber(1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}