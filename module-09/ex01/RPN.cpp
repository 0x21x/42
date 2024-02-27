#include "RPN.hpp"

RPN::RPN() {
	numbers = "0123456789";
	operators = "+-*/";
	nbNumbers = 0;
	nbOperators = 0;
}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN & copy) {
	if (this != &copy) {
		this->numbers = copy.numbers;
		this->operators = copy.operators;
		this->nbNumbers = copy.nbNumbers;
		this->nbOperators = copy.nbOperators;
		this->list = copy.list;
	}
	return *this;
}

int RPN::ctoi(char c) {
    return c - '0';
}

bool RPN::checkStr(std::string str){
	std::string numbers = "0123456789";
	std::string operators = "+-*/";

	std::string::iterator it = str.begin();
	for (; it != str.end(); it++){
		if (numbers.find(*it) != numbers.npos)
			this->nbNumbers++;
		else if (operators.find(*it) != operators.npos)
			this->nbOperators++;
		else
			return false;
	}
	return (it == str.end());
}

void RPN::parse(std::string str) {
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	if (!checkStr(str))
		throw RPN::InvalidFormatException();

	if (this->nbNumbers != this->nbOperators + 1 || this->nbNumbers < 2)
		throw RPN::InvalidFormatException();

	for (std::string::iterator it = str.begin(); it < str.end(); it++)
		this->list.push_back(*it);

	if (this->numbers.find(*this->list.begin()) == this->numbers.npos || this->numbers.find(*std::next(this->list.begin(), 1)) == this->numbers.npos)
		throw RPN::InvalidFormatException();
}

void printlist(std::list<char> list){
	for (std::list<char>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *(it) << " ";
	std::cout << std::endl;
}

int RPN::calculate() {

	std::list<char>::iterator it = this->list.begin();
	int result = this->ctoi(*it);
	this->list.erase(it);

	for (std::list<char>::iterator op; !this->list.empty();) {
		it = this->list.begin();
		if (this->operators.find(*std::next(it, 1)) != this->operators.npos)
			op = std::next(it, 1);
		else
			op = std::next(this->list.begin(), this->list.size() -1);
		switch (*op) {
		case '*':
			result *= this->ctoi(*(it));
			break;
		case '/':
			result /= this->ctoi(*(it));
			break;
		case '+':
			result += this->ctoi(*(it));
			break;
		case '-':
			result -= this->ctoi(*(it));
			break;
		}
		this->list.pop_front();
		if (op != this->list.end()){
			this->list.erase(op);}
		else{
			this->list.pop_back();}
	}
	return result;
}

const char *RPN::InvalidFormatException::what() const throw() {
	return "Invalid Format. Example : \"4 2 3 - +\"";
}
