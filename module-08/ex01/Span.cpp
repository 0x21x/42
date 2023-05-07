#include "Span.hpp"

Span::Span() : n(0) , vec(0) {}

Span::Span(int n) : n(n) , vec(0) {}

Span::Span(Span const &copy) { *this = copy; }

Span::~Span() {}

Span & Span::operator=(Span const & assign) {
	if (this == &assign) { return *this; }
	this->n = assign.n;
	this->vec = assign.vec;
	return *this;
}

void Span::addNumber(int value) {
	if (static_cast<int>(this->vec.size()) == this->n)
		throw Span::SpanFullException();
	vec.push_back(value);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int> tmp(begin, end);
	if (static_cast<int>(tmp.size() + this->vec.size()) > this->n)
		throw Span::SpanFullException();
	this->vec.insert(this->vec.end(), tmp.begin(), tmp.end());
}

void Span::checkShortest(std::vector<int>::iterator nd, int &gap) {
	std::vector<int>::iterator st = nd - 1;
	if (std::max(*st, *nd) - std::min(*st, *nd) > gap)
		return ;
	gap = std::max(*st, *nd) - std::min(*st, *nd);
}

int Span::shortestSpan() {
	if (this->vec.size() < 2)
		throw Span::InsuficientException();
	int	minGap = *std::max_element(this->vec.begin(), this->vec.end());
	std::vector<int>::iterator it = this->vec.begin();
	std::sort(this->vec.begin(), this->vec.end());
	for (; ++it != this->vec.end(); this->checkShortest(it, minGap));
	return minGap;
}

int Span::longestSpan() {
	if (this->vec.size() < 2)
		throw Span::InsuficientException();
	return *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
}

const char * Span::InsuficientException::what() const throw() {
	return "Insuficient numbers in Span.";
}

const char * Span::SpanFullException::what() const throw() {
	return "The Span is already full.";
}