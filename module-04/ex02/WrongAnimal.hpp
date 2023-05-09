#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		// Destructor
		virtual ~WrongAnimal();
		
		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);
		
		void makeSound( void ) const;
		std::string		getType( void ) const;

	protected:
		std::string type;
};

#endif