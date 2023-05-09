#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap tata;

	tata.attack("Arthur");
	tata.beRepaired(10);
	tata.takeDamage(9);
	tata.guardGate();
	return 0; 
}