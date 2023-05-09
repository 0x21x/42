#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal() : type("Wrong animal") { std::cout << "\e[0;33mDefault Constructor called of Wrong Animal\e[0m" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Wrong Animal\e[0m" << std::endl;
	*this = copy;
}

// Destructor
WrongAnimal::~WrongAnimal() { std::cout << "\e[0;31mDestructor called of Wrong Animal\e[0m" << std::endl; }

// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign) {
	if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void WrongAnimal::makeSound( void ) const { std::cout << "Animal make sound !" << std::endl; }

std::string	WrongAnimal::getType( void ) const { return this->type; }