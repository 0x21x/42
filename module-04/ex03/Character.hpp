#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter{

public:

		// Constructors
		Character();
		Character(std::string const & name);
		Character(const Character &copy);

		// Destructor
		~Character();
		
		// Operators
		Character & operator=(const Character &assign);
		
		//Member functions
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

private:

		std::string		name;
		int				count;
		AMateria		*materias[4];

};

#endif