#include "Harl.hpp"

Harl::Harl(void) { std::cout << "Harl created" << std::endl; }

Harl::~Harl(void) { std::cout << "Harl destroyed" << std::endl; }

void Harl::debug( void ) { std::cout << "debug" << std::endl; }

void Harl::info( void ) { std::cout << "info" << std::endl; }

void Harl::warning( void ) { std::cout << "warning" << std::endl; }

void Harl::error( void ) { std::cout << "error" << std::endl; }

void Harl::complain( std::string level ) {
    std::string levels[4] = { "debug", "info", "warning", "error" };
    void (Harl::*harl[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*harl[i])();
            return ;
        }
    }
    std::cout << "Invalid level" << std::endl;
}