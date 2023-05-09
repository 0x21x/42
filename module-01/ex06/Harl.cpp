#include "Harl.hpp"

Harl::Harl(void) { std::cout << "Harl created" << std::endl; }

Harl::~Harl(void) { std::cout << "Harl destroyed" << std::endl; }

void Harl::debug( void ) { std::cout << "[DEBUG]" << std::endl; }

void Harl::info( void ) { std::cout << "[INFO]" << std::endl; }

void Harl::warning( void ) { std::cout << "[WARNING]" << std::endl; }

void Harl::error( void ) { std::cout << "[ERROR]" << std::endl; }

void Harl::complain( std::string level ) {
	std::string levels[4] = { "debug", "info", "warning", "error" };
	void (Harl::*harl[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int lvl = 0;
	for (; lvl < 4; lvl++)
		if (levels[lvl] == level)
			break;
	if (lvl == 4) {
		std::cout << "Invalid level" << std::endl;
		return ;
	}
	for (; lvl < 4; lvl++) {
			(this->*harl[lvl])();
	}
}