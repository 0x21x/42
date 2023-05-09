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
	
	/* Operators */
	Fixed &operator=(const Fixed &copy);

	/* Member functions */
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream&   operator<< (std::ostream &os, Fixed const &f);


#endif

// Path: ex01/Fixed.hpp