#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
#include <algorithm>

class Span {

public:
		Span(int n);
		Span(Span const &copy);
		~Span();
		Span & operator=(Span const & assign);
		void	addNumber(int value);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
		void	checkShortest(std::vector<int>::iterator nd, int &gap);

		class InsuficientException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class SpanFullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

private:
		Span();
		int					n;
		std::vector<int>	vec;
};

#endif