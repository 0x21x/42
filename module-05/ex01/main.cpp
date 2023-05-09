#include "Bureaucrat.hpp"

int main (){

    try {
        Bureaucrat tom("Tom", 1);
        Form form("Form", 100, 1);
        std::cout << tom << std::endl;
        std::cout << form << std::endl;
        tom.signForm(form);
        tom.signForm(form);
        tom.incrementGrade();
    }
    catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}
