#include "Fixed.hpp"

int main(void) {

	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toFloat() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as integer" << std::endl;
	std::cout << "a int is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b int is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c int is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d int is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

// Path: ex01/main.cpp