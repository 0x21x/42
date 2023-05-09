#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
    FragTrap();
    FragTrap( std::string name );
    FragTrap(FragTrap const &s);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &copy);
    void highFivesGuys(void);
};

#endif