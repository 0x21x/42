#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : virtual public FragTrap , virtual public ScavTrap {

private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap( std::string name );
    DiamondTrap(DiamondTrap const &s);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &copy);
    void whoAmI();
};

#endif