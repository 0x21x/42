#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
		std::string type;

public:
		// Constructors
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);

		// Destructor
		virtual ~AMateria();

		// Operators
		AMateria & operator=(const AMateria &assign);

		// Getters and Setters
		std::string const & getType() const;
 		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif