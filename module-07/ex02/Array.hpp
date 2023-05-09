#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(const Array &copy);

		// Destructor
		~Array();

		// Operators
		Array & operator=(const Array &assign);
		T & operator[](int idx);

		//Member functions
		unsigned int	size() const;

		// Class Exception
		class InvalidIndexException : public std::exception {
			public:
				const char *what() const throw();
		};
private:
		T		*arr;
		int		_size;
};

#include "Array.tpp"

#endif