#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap human1;
	DiamondTrap human2(human1);

	human1.attack("Arthur");
	human1.beRepaired(10);
	human1.takeDamage(9);
	human1.highFivesGuys();
	return 0; 
}