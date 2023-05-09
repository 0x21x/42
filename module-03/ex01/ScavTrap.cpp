#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() { std::cout << "ScavTrap Default contrustor called." << std::endl; }

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) { std::cout << "ScavTrap Constructor called." << std::endl; }

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destrustor called." << std::endl; }

ScavTrap::ScavTrap(ScavTrap const  &s) {
    std::cout << "Copy constructor called." << std::endl;
    this->damageAttack = s.damageAttack;
    this->energyPoints = s.energyPoints;
    this->hitPoints = s.hitPoints;
    this->name = s.name;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &copy) {
	std::cout << "Assignation operator called." << std::endl;
    this->damageAttack = copy.damageAttack;
    this->energyPoints = copy.energyPoints;
    this->hitPoints = copy.hitPoints;
    this->name = copy.name;
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode !" << std::endl;
}