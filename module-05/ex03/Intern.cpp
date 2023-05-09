#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern() {
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
	*this = copy;
}


// Destructor
Intern::~Intern() {
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign) {
	std::cout << "\e[0;33mAssignation operator called of Intern\e[0m" << std::endl;
	if (this == &assign) { return *this; }
	return *this;
}

Form *	Intern::makeForm(std::string formName, std::string target) {
	const std::string formsNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (int i = 0; i < 3; i++) {
		if (formName == formsNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++) {
				if (j != i) {
					delete forms[j];
				}
			}
			return forms[i];
		}
	}
	std::cout << "Intern can't create " << formName << " because it doesn't exist" << std::endl;
	return NULL;
}
