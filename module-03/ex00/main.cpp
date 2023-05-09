#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap human1("Tom");
	ClapTrap human2(human1);
	ClapTrap human3;
	human3 = human1;

	human1.attack("target1");
	human2.attack("target2");
	human1.beRepaired(10);
	human1.takeDamage(9);
	return 0; 
}