#include "Array.hpp"

// Constructors
template <typename T>
Array<T>::Array(){
	this->arr = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->arr = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &copy) {
	*this = copy;
}

// Destructor
template <typename T>
Array<T>::~Array() {
	if (this->arr) { delete [] this->arr; }
}

// Operators
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &assign) {
	if (this == &assign) { return *this; }
	this->arr = new T[assign._size];
	for (int i = 0; i < assign._size; i++) {
		this->arr[i] = assign.arr[i];
	}
	this->_size = assign._size;
	return *this;
}

template <typename T>
T & Array<T>::operator[](int idx) {
	if (idx >= 0 && idx < this->_size)
		return this->arr[idx];
	else
		throw Array<T>::InvalidIndexException();
}

//Member functions
template <typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

// Class Exception
template <typename T>
const char *Array<T>::InvalidIndexException::what() const throw() {
	return  "Exception: \e[31mInvalid index!\e[0m";
}
