#ifndef SCALARSTRING_HPP
#define SCALARSTRING_HPP

#include <string>
#include <exception>
#include <limits>

class ScalarString {
public:
	ScalarString(const char* number);
	ScalarString(const ScalarString& scalarString);
	virtual ~ScalarString();

	ScalarString& operator = (const ScalarString& scalarString);
	operator int() const;
	operator char() const;
	operator float() const;
	operator double() const;

	class ImpossibleException : public std::exception {
	public:
		const char* what() const throw();
	};
	class NonDisplayableException : public std::exception {
	public:
		const char* what() const throw();
	};

private:
	ScalarString();
	std::string number;
};

#endif
