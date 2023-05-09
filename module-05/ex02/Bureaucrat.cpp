#include "Bureaucrat.hpp"

// Constructors  && Destructors
Bureaucrat::Bureaucrat() : name("default"), grade(this->minGrade) {
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

void Bureaucrat::signForm(Form &form) const{
	if (form.getSign()) {
		std::cout << this->name << " couldn’t sign " << form.getName() << " because it's already signed" << std::endl;
	}
	else if (this->grade > form.getExecGrade()) {
		std::cout << this->name << " couldn’t sign " << form.getName() << " because it's grade is too low" << std::endl;
	}
	else {
		std::cout << this->name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

void Bureaucrat::executeForm(const Form &form) const {
	if (!form.getSign()) {
		std::cout << this->name << " couldn’t execute " << form.getName() << " because it's not signed" << std::endl;
	}
	else if (this->grade > form.getExecGrade()) {
		std::cout << this->name << " couldn’t execute " << form.getName() << " because it's grade is too low" << std::endl;
	}
	else {
		std::cout << this->name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
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