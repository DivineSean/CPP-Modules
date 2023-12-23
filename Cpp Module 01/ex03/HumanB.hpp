#pragma once
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *Weapon;
    public:
        HumanB(std::string name);
        void    setWeapon(class Weapon &Weapon);
        void    attack();
        ~HumanB();
};