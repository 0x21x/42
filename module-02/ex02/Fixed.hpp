#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

	private:
		/* Private member variables */
		int					_value;
		static const int	_fractionalBits = 8;


	public:

		/* Construtors */
		Fixed();
		Fixed(const int value);

		Fixed(const float value);
		Fixed(const Fixed &copy);


		/* Destructor */
		~Fixed();

		/* Operator */
		Fixed &operator=  (const Fixed &copy);

		bool   operator<  ( Fixed const &a);
		bool   operator>  ( Fixed const &a);
		bool   operator<= ( Fixed const &a);
		bool   operator>= ( Fixed const &a);
		bool   operator== ( Fixed const &a);
		bool   operator!= ( Fixed const &a);

		Fixed   operator+ ( Fixed const &a);
		Fixed   operator- ( Fixed const &a);
		Fixed   operator* ( Fixed const &a);
		Fixed   operator/ ( Fixed const &a);

		Fixed   operator++ ( void );
		Fixed   operator-- ( void );
		Fixed   operator++ ( int );
		Fixed   operator-- ( int );

	/* Member functions */
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	static Fixed	min( Fixed const &a, Fixed const &b );
	static Fixed	min( Fixed &a, Fixed &b );
	static Fixed	max( Fixed const &a, Fixed const &b );
	static Fixed	max( Fixed &a, Fixed &b );

};

std::ostream&   operator<< (std::ostream &os, Fixed const &f);

#endif

// Path: ex01/Fixed.hpp