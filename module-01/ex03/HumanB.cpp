#include "HumanB.hpp"

HumanB::HumanB(std::string name) : Name(name) {}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->Name;
    std::cout << " attacks with his ";
    std::cout << this->weapon->getType();
    std::cout << std::endl;
}