#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("default") {
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "\e[0;33mConstructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	std::cout << "\e[0;33mAssignation operator called of PresidentialPardonForm\e[0m" << std::endl;
	if (this == &assign) { return *this; }
	this->target = assign.getTarget();
	this->checkGrade();
	this->checkExecGrade();
	return *this;
}

// Member Functions
std::string PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::checkGrade() {
	if (this->getGrade() < 25) { throw Form::GradeTooLowException(); }
}

void PresidentialPardonForm::checkExecGrade() {
	if (this->getExecGrade() < 5) { throw Form::GradeTooLowException(); }
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false) { throw Form::FormNotSign(); }
	if (executor.getGrade() > this->getExecGrade()) { throw Form::GradeTooLowException(); }
	std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
