#include "Dog.hpp"

// Constructors
Dog::Dog() {
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(const Dog &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

// Destructor
Dog::~Dog() {
	if (this->brain) { delete this->brain; }
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign) {
	if (&assign == this)
		return *this;
	if (this->brain) { delete this->brain; }
	this->brain = new Brain();
	this->brain = assign.brain;
	this->type = assign.getType();
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "Wouaf Wouaf !" << std::endl; }