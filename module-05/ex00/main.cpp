#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat	tom("Tom", 150);
        std::cout << tom;
		tom.decrementGrade();
    }
    catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
    }
}