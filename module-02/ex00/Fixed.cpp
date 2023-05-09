#include "Fixed.hpp"

// Constructors
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed & Fixed::operator=(Fixed const &copy) {
	std::cout << "Assignation operator called" << std::endl;
	_value = copy.getRawBits();
	return *this;
}


// Destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }


// Member functions
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ) { _value = raw; }

// Path: ex00/Fixed.cpp