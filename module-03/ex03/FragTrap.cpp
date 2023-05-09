#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") { 
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->damageAttack = 30;
    std::cout << "FragTrap Default contrustor called." << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->damageAttack = 30;
	std::cout << "FragTrap Constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const  &s) {
    std::cout << "Copy constructor called." << std::endl;
    this->damageAttack = s.damageAttack;
    this->energyPoints = s.energyPoints;
    this->hitPoints = s.hitPoints;
    this->name = s.name;
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destrustor called." << std::endl; }

FragTrap & FragTrap::operator=(FragTrap const &copy) {
	std::cout << "Assignation operator called." << std::endl;
    this->damageAttack = copy.damageAttack;
    this->energyPoints = copy.energyPoints;
    this->hitPoints = copy.hitPoints;
    this->name = copy.name;
	return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Hey ! Do you want high guys like a bitch couple." << std::endl;
}