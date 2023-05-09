#include "Fixed.hpp"

/* Construtors */
Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called" << std::endl;
	_value = value * (1 << _fractionalBits);
}

Fixed::Fixed(const Fixed &copy) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/* Destructor */
Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}


/* Member functions */
int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits( int const raw ) { _value = raw; }

int		Fixed::toInt() const {
	return this->_value / (1 << this->_fractionalBits);
}

float		Fixed::toFloat() const {
	return (float)this->_value / (1 << this->_fractionalBits);
}

/* Operators */
std::ostream&   operator<< (std::ostream &os, Fixed const &f) {
	os << f.toFloat();
	return os;
}

Fixed & Fixed::operator=(Fixed const &copy) {
	//std::cout << "Assignation operator called" << std::endl;
	_value = copy.getRawBits();
	return *this;
}

bool   Fixed::operator< ( Fixed const &a) { return this->_value < a._value; };
bool   Fixed::operator> ( Fixed const &a) { return this->_value > a._value; };
bool   Fixed::operator<= ( Fixed const &a) { return this->_value <= a._value; };
bool   Fixed::operator>= ( Fixed const &a) { return this->_value >= a._value; };
bool   Fixed::operator== ( Fixed const &a) { return this->_value == a._value; };
bool   Fixed::operator!= ( Fixed const &a) { return this->_value != a._value; };

Fixed   Fixed::operator+ ( Fixed const &a) { return Fixed( this->toFloat() + a.toFloat() ); };
Fixed   Fixed::operator- ( Fixed const &a) { return Fixed( this->toFloat() - a.toFloat() ); };
Fixed   Fixed::operator* ( Fixed const &a) { return Fixed( this->toFloat() * a.toFloat() ); };
Fixed   Fixed::operator/ ( Fixed const &a) { return Fixed( this->toFloat() / a.toFloat() ); };

Fixed   Fixed::operator++ ( void ) { 
	this->_value += 1 * (1 << this->_fractionalBits);
	return Fixed( this->toFloat());
};

Fixed   Fixed::operator-- ( void ) {
	this->_value -= 1 / (1 << this->_fractionalBits);
	return Fixed( this->toFloat() - 1);
};

Fixed   Fixed::operator++ ( int ) { 
	this->_value += 1 * (1 << this->_fractionalBits);
	return Fixed( this->toFloat());
};

Fixed   Fixed::operator-- ( int ) {
	this->_value -= 1 / (1 << this->_fractionalBits);
	return Fixed( this->toFloat() - 1);
};

Fixed	Fixed::min( Fixed const &a, Fixed const &b ){
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed	Fixed::min( Fixed &a, Fixed &b ) {
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed	Fixed::max( Fixed const &a, Fixed const &b ) {
	return a.toFloat() > b.toFloat() ? a : b;
}

Fixed	Fixed::max( Fixed &a, Fixed &b ) {
	return a.toFloat() > b.toFloat() ? a : b;
}

// Path: ex01/main.cpp