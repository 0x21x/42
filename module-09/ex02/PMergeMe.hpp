#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iterator>
#include <deque>
#include <vector>
#include <utility>
#include <chrono>

class PMergeMe {
private:

public:
		bool	odd;

		PMergeMe();
		PMergeMe(const PMergeMe &copy);
		~PMergeMe();
		PMergeMe& operator=(const PMergeMe &copy);

		void checkArg(char **arr);
		class InvalidFormatException : public std::exception {
			public:
					virtual const char *what() const throw();
		};
		class NotPositiveInteger : public std::exception {
			public:
					virtual const char *what() const throw();
		};
};

#endif