#include "Animal.hpp"

// Constructors
Animal::Animal() : type("animal") { std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl; }

Animal::Animal(const Animal &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Animal::~Animal() { std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl; }

// Operators
Animal const & Animal::operator=(Animal const &assign) {
		if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void Animal::makeSound( void ) const { std::cout << "Animal make sound !" << std::endl; }

std::string	Animal::getType( void ) const { return this->type; }