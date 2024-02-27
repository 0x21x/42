#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <exception>
#include <iterator>

class RPN {

public:
		RPN();
		RPN(const RPN &copy);
		~RPN();

		RPN& operator=(const RPN &copy);

		void parse(std::string str);
		int calculate();


private:
		bool checkStr(std::string str);
		int ctoi(char c);

		std::list<char>	list;
		std::string			operators;
		std::string			numbers;
		int					nbOperators;
		int					nbNumbers;

		class InvalidFormatException : public std::exception {
				public:
					virtual const char *what() const throw();
			};

};

#endif