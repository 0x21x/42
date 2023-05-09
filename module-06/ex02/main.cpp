#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * gernerate(void) {
	int r = rand() % 3;
	if (r == 0) {
		std::cout << "create A\n";
		return (new A());
	}
	else if (r == 1) {
		std::cout << "create B\n";
		return (new B());
	}
	else {
		std::cout << "create C\n";
		return (new C());
	}
}

void identify_from_pointer(Base *p) {
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "C\n";
}

void identify_from_reference(Base & p) {
	identify_from_pointer(&p);
}

int main() {
	srand(time(NULL));
	Base* base = gernerate();
	identify_from_pointer(base);
	identify_from_reference(*base);
}