#include "Zombie.hpp"

int main( void ) {

	Zombie *zombie;
	zombie = newZombie( "Foo" );
	zombie->announce();
	delete zombie;

	randomChump( "Bar" );
	return 0;
}