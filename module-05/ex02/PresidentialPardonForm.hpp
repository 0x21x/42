#ifndef PRESIENTIALPARDONFORM_HPP
# define PRESIENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:
		// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		// Member Functions
		void			execute(const Bureaucrat &bureaucrat) const;
		std::string		getTarget() const;

private:
		PresidentialPardonForm();
		void		checkGrade();
		void		checkExecGrade();
		
		std::string	target;
};

#endif