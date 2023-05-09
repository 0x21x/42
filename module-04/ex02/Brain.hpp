#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		// Destructor
		~Brain();

		// Operators
		Brain const & operator=(Brain const &assign);

	private:
		std::string *ideas[100];
};

#endif