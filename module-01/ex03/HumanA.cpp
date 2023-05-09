#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : Name(name), weapon(weapon) {}

void    HumanA::attack() {
    std::cout << this->Name;
    std::cout << " attacks with his ";
    std::cout << this->weapon.getType();
    std::cout << std::endl;
}