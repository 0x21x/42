#ifndef HUMANA_HPP
#define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {

    private:
        std::string Name;
        Weapon      &weapon;

    public:
        HumanA(std::string, Weapon &weapon);
        void	attack();
};

#endif