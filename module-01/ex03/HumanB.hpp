#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {

    private:
        std::string Name;

    public:
        Weapon      *weapon;
        HumanB(std::string);
        void	attack();
        void	setWeapon(Weapon &weapon);
};

#endif