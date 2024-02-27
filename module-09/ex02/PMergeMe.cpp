#include "PMergeMe.hpp"

PMergeMe::PMergeMe() :odd(false){}

PMergeMe::PMergeMe(const PMergeMe &copy) {
    *this = copy;
}

PMergeMe::~PMergeMe() {}

PMergeMe& PMergeMe::operator=(const PMergeMe &copy) {
    if (this != &copy) {
        this->odd = copy.odd;
    }
    return *this;
}

void PMergeMe::checkArg(char **av){
    for (size_t i = 0; av[i]; i++) {
        std::string s = av[i];
        bool onlyDigits = (s.find_first_not_of( "0123456789" ) == std::string::npos);
        if (!onlyDigits)
            throw PMergeMe::NotPositiveInteger();
        size_t value = std::stoll(s);
        if (value > INT_MAX)
            throw PMergeMe::NotPositiveInteger();
    }
}

const char *PMergeMe::InvalidFormatException::what() const throw () {
    return "Invalid Format. Example : 4 2 3 1 5";
}

const char *PMergeMe::NotPositiveInteger::what() const throw () {
    return "Not positive integer arguments";
}
