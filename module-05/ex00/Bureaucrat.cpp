#include "Bureaucrat.hpp"

// Constructors  && Destructors
Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) , grade(grade) {
	std::cout << "\e[0;33mConstructor called of Bureaucrat\e[0m" << std::endl;
	this->checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat() { std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl; }

// Operator =
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign) {
	if (this == &assign) { return *this; }
	this->grade = assign.grade;
	this->name = assign.getName();
	this->checkGrade();
	return *this;
}

// Overload operator <<
std::ostream & operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

// Member Functions
int Bureaucrat::getGrade() const {
	return this->grade;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::incrementGrade() {
	this->grade--;
	this->checkGrade();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
	this->checkGrade();
}

// Excpetion
void Bureaucrat::checkGrade() {
	if (this->grade < this->maxGrade) { throw Bureaucrat::GradeTooHighException(); }
	if (this->grade > this->minGrade) { throw Bureaucrat::GradeTooLowException(); }
}

// Exception Class
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too big !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low !";
}