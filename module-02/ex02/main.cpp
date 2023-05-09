#include "Fixed.hpp"

int main(void) {
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;

	std::cout << "a(float) is " << a.toFloat() << std::endl;
	std::cout << "b(float) is " << b.toFloat() << std::endl;
	std::cout << "c(float) is " << c.toFloat() << std::endl;
	std::cout << "d(float) is " << d.toFloat() << std::endl;
	std::cout << std::endl;

	std::cout << "a(int) is " << a.toInt() << std::endl;
	std::cout << "b(int) is " << b.toInt() << std::endl;
	std::cout << "c(int) is " << c.toInt() << std::endl;
	std::cout << "d(int) is " << d.toInt() << std::endl;
	std::cout << std::endl;

	std::cout << "a < b = ";
	if (a < b) { std::cout << "true" << std::endl; }
	else { std::cout << "false" << std::endl; }
	std::cout << std::endl;

	std::cout << "min between " << b << " and " << d << " is " << Fixed::min( b, d ) << std::endl;
	std::cout << "max between " << b << " and " << d << " is " << Fixed::max( b, d ) << std::endl;
	std::cout << "min between " << a << " and " << b << " is " << Fixed::min( a, b ) << std::endl;
	std::cout << "max between " << a << " and " << b << " is " << Fixed::max( a, b ) << std::endl;
	return 0;
}

// Path: ex01/main.cpp