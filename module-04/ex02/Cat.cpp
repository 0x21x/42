#include "Cat.hpp"

// Constructors
Cat::Cat() {
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
	*this = copy;
}


// Destructor
Cat::~Cat() {
	if (this->brain) { delete this->brain; }
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

// Operators
Cat & Cat::operator=(const Cat &assign) {
	if (&assign == this) { return *this; }
	if (this->brain) { delete this->brain; }
	this->brain = new Brain();
	this->brain = assign.brain;
	this->type = assign.getType();
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "Miaou Miaou !" << std::endl; }