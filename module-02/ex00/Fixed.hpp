#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

	private:
	int					_value;
	static const int	_fractionalBits = 8;


	public:
		// Construtors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		// Destructor
		~Fixed();
	
	// Member functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

#endif

// Path: ex00/Fixed.hpp