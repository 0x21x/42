#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:
		// Constructors
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		// Destructor
		~Bureaucrat();

		// Member Functions
		Bureaucrat & operator=(const Bureaucrat &assign);
		int					getGrade() const;
		std::string			getName() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form) const;


		// Exception Class
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

private:
		Bureaucrat();

		std::string	name;
		int					grade;

		static const int			maxGrade = 1;
		static const int			minGrade = 150;

		void				checkGrade();
};

std::ostream & operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif