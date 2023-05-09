#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : type("AMateria") { std::cout << "\e[0;33mDefault Constructor called of AMateria\e[0m" << std::endl; }

AMateria::AMateria(std::string const & type) : type(type) { std::cout << "\e[0;33mConstructor called of AMateria\e[0m" << std::endl; }

AMateria::AMateria(const AMateria &copy) {
	std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
	*this = copy;
}

// Destructor
AMateria::~AMateria() { std::cout << "\e[0;31mDestructor called of AMateria\e[0m" << std::endl; }

// Operators
AMateria & AMateria::operator=(const AMateria &assign) {
	if (&assign == this) { return *this; }
	this->type = assign.type;
	return *this;
}

std::string const & AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter& target) {
	std::cout << " * AMateria " << target.getName() << " *" << std::endl;
}