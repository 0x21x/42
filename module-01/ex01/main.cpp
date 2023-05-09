#include "Zombie.hpp"	

int main( void ) {

	Zombie *zombie;
	zombie = zombieHorde(10, "Foo" );
	for (int i = 0; i < 10; i++) {
		zombie[i].announce();
	}
	delete[] zombie;
	system("leaks zombieHorde");
	return 0;
}