#ifndef ROBOTOMYREQUESTFORM_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

public:
		// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		// Destructor
		~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
		// Member Functions
		void			execute(const Bureaucrat &bureaucrat) const;
		std::string		getTarget() const;

private:
		RobotomyRequestForm();
		void		checkGrade();
		void		checkExecGrade();
		
		std::string	target;
};

#endif