#pragma once
#include <iostream>

class ClapTrap
{
    private:
        std::string     name;
        unsigned int    Hit_Points;
        unsigned int    Energy_Points;
        unsigned int    Attack_Damage;
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap(const ClapTrap &copy);
        ClapTrap    &operator=(const ClapTrap &copy);
        void    attack( const std::string &target );
        void    takeDamage( unsigned int amount );
        void    beRepaired( unsigned int amount );
        ~ClapTrap();
};