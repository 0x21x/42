#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <exception>
#include <stack>
#include <deque>
#include <iterator>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {

public:
		MutantStack() {}
		MutantStack(MutantStack const &copy) { *this = copy; }
		~MutantStack() {}
		MutantStack & operator=(MutantStack const &copy) {
			(void)copy;
			return *this;
		}
		typedef typename std::deque<T>::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif