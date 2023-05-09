#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main (){



    try {
        /* ShrubberyCreationForm */
        Bureaucrat scav("Scav", 1);
        ShrubberyCreationForm form("home");
        form.beSigned(scav);
        scav.executeForm(form);
        /* Will write in <target>_shrubbery an ascii tree /!\ */
        std::cout << std::endl;
    }
    catch (const std::exception &error) {
        std::cerr << "[0]" << error.what() << std::endl;
    }


    try {
        /* ShrubberyCreationForm */
        Bureaucrat tom("Tom", 1);
        ShrubberyCreationForm form1("home1");
        form1.beSigned(tom);
        /* Will write in <target>_shrubbery an ascii tree /!\ */
        form1.execute(tom);
        std::cout << std::endl;
    }
    catch (const std::exception &error) {
        std::cerr << "[1]" << error.what() << std::endl;
    }


    try {
        /* RobotomyRequestForm */
        Bureaucrat bob("Bob", 40);
        RobotomyRequestForm form2("home2");
        form2.beSigned(bob);
        /* Will make drilling noises and ann announces 
        that the <target> has been robotized 50% of the time*/
        form2.execute(bob);
        std::cout << std::endl;
    }
    catch (const std::exception &error) {
        std::cerr << "[2] " << error.what() << std::endl;
    }


    try {
         /* PresidentialPardonForm */
        Bureaucrat jim("Jim", 1);
        PresidentialPardonForm form3("home3");
        form3.beSigned(jim);
        /* Will announce that <target> has been pardoned by Zafod Beeblebrox */
        form3.execute(jim);
        std::cout << std::endl;
    }
    catch (const std::exception &error) {
        std::cerr << "[3] " << error.what() << std::endl;
    }

    try {
        /* Intern */
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        (void)rrf;
    }
    catch (const std::exception &error) {
        std::cerr << "[4] " << error.what() << std::endl;
    }
}
