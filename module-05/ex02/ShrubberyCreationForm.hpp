#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:
		// Constructors
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		// Destructor
		~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
		// Member Functions
		void			execute(const Bureaucrat &bureaucrat) const;
		std::string		getTarget() const;

private:
		ShrubberyCreationForm();
		void		checkGrade();
		void		checkExecGrade();
		
		std::string	target;
};

#endif