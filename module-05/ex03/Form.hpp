#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:

		// Constructors
		Form(const std::string name, int grade, int execGrade);
		Form(const Form &copy);
		
		// Destructor
		virtual ~Form();
		
		// Operators
		Form & operator=(const Form &assign);

		// Member Functions
		int					getGrade() const;
		int					getExecGrade() const;
		std::string	getName() const;
		bool				getSign() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(const Bureaucrat &bureaucrat) const = 0;
		

		// Exception Class
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class IncorrectGrade : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSign : public std::exception {
			public:
				virtual const char* what() const throw();
		};

protected:

		Form();
		virtual void		checkGrade();
		virtual void		checkExecGrade();

		const std::string					name;
		int							grade;
		int							execGrade;
		bool						sign;

		static const int			maxGrade = 1;
		static const int			minGrade = 150;
};

std::ostream & operator<<(std::ostream &out, const Form &form);

#endif