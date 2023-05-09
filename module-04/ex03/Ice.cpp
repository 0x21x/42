#include "Ice.hpp"

// Constructors
Ice::Ice() {
	std::cout << "\e[0;33mDefault Constructor called of Ice\e[0m" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Ice\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Ice::~Ice() { std::cout << "\e[0;31mDestructor called of Ice\e[0m" << std::endl; }

// Operators
Ice & Ice::operator=(const Ice &assign) {
	std::cout << "\e[0;33mAssignation operator called of Ice\e[0m" << std::endl;
	if (&assign == this) { return *this; }
	this->type = assign.type;
	return *this;
}

// Member functions
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria * Ice::clone() const { return new Ice(); }