#include "Fixed.hpp"

/* Construtors */
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_value = value * (1 << _fractionalBits);
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}



/* Operators */
Fixed & Fixed::operator=(Fixed const &copy) {
	std::cout << "Assignation operator called" << std::endl;
	_value = copy.getRawBits();
	return *this;
}

std::ostream&   operator<< (std::ostream &os, Fixed const &f) {
	os << f.toFloat();
	return os;
}



/* Destructor */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }



/* Member functions */
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_value / (1 << this->_fractionalBits));
}

int Fixed::toInt( void ) const {
	return (this->_value / (1 << this->_fractionalBits));
}

void Fixed::setRawBits( int const raw ) { _value = raw; }