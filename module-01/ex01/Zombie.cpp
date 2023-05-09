#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie( std::string name ) {
	this->Name = name;
	std::cout << this->Name;
	std::cout << ":";
	std::cout << " Born" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->Name;
	std::cout << ":";
	std::cout << " Died" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->Name;
	std::cout << ":";
	std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}