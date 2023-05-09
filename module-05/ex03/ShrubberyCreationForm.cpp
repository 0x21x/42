#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("default") {
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "\e[0;33mConstructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) {
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign) {
	std::cout << "\e[0;33mAssignation operator called of ShrubberyCreationForm\e[0m" << std::endl;
	if (this == &assign) { return *this; }
	this->target = assign.getTarget();
	this->checkGrade();
	this->checkExecGrade();
	return *this;
}

// Member Functions
std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::checkGrade() {
	if (this->getGrade() < 145) { throw Form::GradeTooLowException(); }
}

void ShrubberyCreationForm::checkExecGrade() {
	if (this->getExecGrade() < 137) { throw Form::GradeTooLowException(); }
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false) { throw Form::FormNotSign(); }
	if (executor.getGrade() > this->getExecGrade()) { throw Form::GradeTooLowException(); }
	std::ofstream file;
	file.open(this->getTarget() + "_shrubbery");
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\" << std::endl;
	file.close();
}
