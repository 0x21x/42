#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		void makeSound( void ) const;
};

#endif