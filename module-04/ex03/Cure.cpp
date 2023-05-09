#include "Cure.hpp"

// Constructors
Cure::Cure() {
	std::cout << "\e[0;33mDefault Constructor called of Cure\e[0m" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Cure\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Cure::~Cure() { std::cout << "\e[0;31mDestructor called of Cure\e[0m" << std::endl; }

// Operators
Cure & Cure::operator=(const Cure &assign) {
	std::cout << "\e[0;33mAssignation operator called of Cure\e[0m" << std::endl;
	if (&assign == this) { return *this; }
	this->type = assign.type;
	return *this;
}

// Member functions
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria * Cure::clone() const { return new Cure(); }