#include "ClapTrap.hpp"

/* Constructors & Destructor */
ClapTrap::ClapTrap() : name("default") , hitPoints(10) , energyPoints(10), damageAttack(0) {
    std::cout << "ClapTrap Default contrustor called." << std::endl;
}

ClapTrap::ClapTrap(std::string Name ) : name(Name) , hitPoints(10) , energyPoints(10), damageAttack(0) {
    std::cout << "Contrustor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const  &s) {
    std::cout << "Copy constructor called." << std::endl;
    this->damageAttack = s.damageAttack;
    this->energyPoints = s.energyPoints;
    this->hitPoints = s.hitPoints;
    this->name = s.name;
}

ClapTrap::~ClapTrap() { std::cout << "Destrustor called." << std::endl; }

ClapTrap & ClapTrap::operator=(ClapTrap const &copy) {
	std::cout << "Assignation operator called." << std::endl;
    this->damageAttack = copy.damageAttack;
    this->energyPoints = copy.energyPoints;
    this->hitPoints = copy.hitPoints;
    this->name = copy.name;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << this->name;
    std::cout << " attacks " << target;
    std::cout << ", causing " << this->damageAttack;
    std::cout << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->energyPoints && this->hitPoints) {
        this->hitPoints -= amount;
        this->energyPoints--;
        std::cout << "Take Damage : " << amount << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints) {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "Take Health : " << amount << std::endl;
    }
}
