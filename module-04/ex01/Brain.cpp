#include "Brain.hpp"

// Constructors
Brain::Brain() { std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl; }

Brain::Brain(const Brain &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Brain::~Brain() { std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl; }

// Operators
Brain const & Brain::operator=(Brain const &assign) {
	if (&assign == this)
		return *this;
	for (int i = 0; i < 100; i++)
	 	this->ideas[i] = assign.ideas[i];
	return *this;
}
