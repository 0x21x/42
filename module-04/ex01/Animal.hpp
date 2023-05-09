#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		// Destructor
		virtual ~Animal();
		
		// Operators
		Animal const & operator=(Animal const &assign);
		
		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;


	protected:
		std::string type;
};

#endif