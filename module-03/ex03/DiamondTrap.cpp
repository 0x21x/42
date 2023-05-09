#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap() {
	this->name = "default";
	this->energyPoints = ScavTrap::energyPoints;
	this->hitPoints = FragTrap::hitPoints;
	this->damageAttack = FragTrap::damageAttack;
	std::cout << "DiamondTrap Default contrustor called." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : FragTrap() {
	std::cout << "DiamondTrap Constructor called." << std::endl;
	this->name = name + "_clap_name";
	this->energyPoints = 10;
	this->hitPoints = FragTrap::hitPoints;
	this->damageAttack = FragTrap::damageAttack;
}

DiamondTrap::DiamondTrap(DiamondTrap const  &s) {
    std::cout << "Copy constructor called." << std::endl;
    this->damageAttack = s.damageAttack;
    this->energyPoints = s.energyPoints;
    this->hitPoints = s.hitPoints;
    this->name = s.name;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destrustor called." << std::endl; }

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &copy) {
	std::cout << "Assignation operator called." << std::endl;
	this->name = copy.name;
	this->damageAttack = copy.damageAttack;
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->name = copy.name;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << this->name << std::endl;
	std::cout << ClapTrap::name << std::endl;
}
