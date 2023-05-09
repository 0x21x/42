#ifndef __ScavTrap_HPP__
#define __ScavTrap_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
    ScavTrap();
    ScavTrap( std::string name );
    ScavTrap(ScavTrap const &s);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &copy);
    void guardGate();
};

#endif