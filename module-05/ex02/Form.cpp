#include "Form.hpp"

// Constructors
Form::Form() : name("default"), grade(minGrade), execGrade(minGrade) {
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
	this->sign = false;
}

Form::Form(const std::string name, int grade, int execGrade) : name(name), grade(grade), execGrade(execGrade) {
	std::cout << "\e[0;33mConstructor called of Form\e[0m" << std::endl;
	this->sign = false;
	this->checkGrade();
	this->checkExecGrade();
}

Form::Form(const Form &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Form::~Form() { std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl; }

// Operator
Form & Form::operator=(const Form &assign) {
	if (this == &assign) { return *this; }
	this->grade = assign.grade;
	this->execGrade = assign.execGrade;
	this->checkGrade();
	this->checkExecGrade();
	return *this;
}

// Overload operator <<
std::ostream & operator<<(std::ostream &out, const Form &form) {
	out << form.getName() << ", form grade : " << form.getGrade() << ", form execGrade : " << form.getExecGrade() << std::endl;
	return out;
}

// Member Functions
int Form::getGrade() const {
	return this->grade;
}

int Form::getExecGrade() const {
	return this->execGrade;
}

std::string Form::getName() const {
	return this->name;
}

bool Form::getSign() const {
	return this->sign;
}

void Form::checkGrade() {
	if (this->grade < this->maxGrade) { throw Form::GradeTooHighException(); }
	if (this->grade > this->minGrade) { throw Form::GradeTooLowException(); }
}

void Form::checkExecGrade() {
	if (this->execGrade < this->maxGrade) { throw Form::GradeTooHighException(); }
	if (this->execGrade > this->minGrade) { throw Form::GradeTooLowException(); }
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->grade)
		this->sign = true;
	else { throw Form::GradeTooLowException(); }
}

// Exception Class
const char* Form::GradeTooHighException::what() const throw() {
	return "\e[0;31mForm Grade too big !\e[0m";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "\e[0;31mForm Grade too low !\e[0m";
}

const char* Form::IncorrectGrade::what() const throw() {
	return "\e[0;31mGrade is incorrect\e[0m";
}

const char* Form::FormNotSign::what() const throw() {
	return "\e[0;31mForm is not sign\e[0m";
}