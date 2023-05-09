#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {

protected:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         damageAttack;
public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(ClapTrap const &s);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif