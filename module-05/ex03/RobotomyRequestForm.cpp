#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default") {
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "\e[0;33mConstructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) {
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	std::cout << "\e[0;33mAssignation operator called of RobotomyRequestForm\e[0m" << std::endl;
	if (this == &assign) { return *this; }
	this->target = assign.getTarget();
	this->checkGrade();
	this->checkExecGrade();
	return *this;
}

// Member Functions
std::string RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::checkGrade() {
	if (this->getGrade() < 72) { throw Form::GradeTooLowException(); }
}

void RobotomyRequestForm::checkExecGrade() {
	if (this->getExecGrade() < 45) { throw Form::GradeTooLowException(); }
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false) { throw Form::FormNotSign(); }
	if (executor.getGrade() > this->getExecGrade()) { throw Form::GradeTooLowException(); }
	std::cout << "Drilling noises..." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1) {
		std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
	}
	else {
		std::cout << this->getTarget() << " operation has been failed !" << std::endl;
	}
}
