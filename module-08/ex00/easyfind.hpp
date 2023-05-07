#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <exception>

class ValueIncorrect : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "The value isn't found in container.";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator pos = std::find(container.begin(), container.end(), value);
	if (pos == container.end())
		throw ValueIncorrect();
	return pos;
}