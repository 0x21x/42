#include "ClapTrap.hpp"

/* Constructors & Destructor */
ClapTrap::ClapTrap() : name("default") , hitPoints(100) , energyPoints(50), damageAttack(20) {
    std::cout << "ClapTrap Default contrustor called." << std::endl;
}

ClapTrap::ClapTrap(std::string Name ) : name(Name) , hitPoints(100) , energyPoints(50), damageAttack(20) {
    std::cout << "ClapTrap Contrustor called." << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destrustor called." << std::endl; }

ClapTrap::ClapTrap(ClapTrap const  &s) {
    std::cout << "Copy constructor called." << std::endl;
    this->damageAttack = s.damageAttack;
    this->energyPoints = s.energyPoints;
    this->hitPoints = s.hitPoints;
    this->name = s.name;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &copy) {
	std::cout << "ClapTrap Assignation operator called." << std::endl;
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
        std::cout << "Aie ! i have take " << amount << " damage. Fuck !" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints) {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "Take Health : " << amount << std::endl;
    }
}
