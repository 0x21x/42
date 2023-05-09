#include "ScalarString.hpp"

ScalarString::ScalarString(){}

ScalarString::ScalarString(const char* s) : number(static_cast<std::string>(s)){}

ScalarString::ScalarString(const ScalarString& scalarString) {
	*this = scalarString;
}

ScalarString::~ScalarString() {}

ScalarString& ScalarString::operator = (const ScalarString& scalarString) {
	number = scalarString.number;
	return *this;
}

ScalarString::operator int() const {
	double n = static_cast<double>(*this);
	if (isnan(n) ||
		!(std::numeric_limits<int>::min() <= n && n <= std::numeric_limits<int>::max()))
	throw ImpossibleException();
	return static_cast<int>(n);
}

ScalarString::operator char() const {
	int n = static_cast<int>(*this);
	if (!(std::numeric_limits<char>::min() <= n && n <= std::numeric_limits<char>::max()))
		throw ImpossibleException();
	if (!(32 <= n && n <= 126))
		throw NonDisplayableException();
	return static_cast<char>(n);
}

ScalarString::operator float() const {
	double n = static_cast<double>(*this);
	return static_cast<float>(n);
}

ScalarString::operator double() const {
	char* end;
	double n = std::strtod(number.c_str(), &end);
	if (number.c_str() == end)
		throw ImpossibleException();
	return n;
}


const char* ScalarString::ImpossibleException::what() const throw() {
  return "impossible";
}

const char* ScalarString::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
