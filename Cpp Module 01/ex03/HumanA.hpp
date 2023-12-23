#pragma once
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &Weapon;
    public:
        HumanA(std::string name, class Weapon &Weapon);
        void    attack();
        ~HumanA();
};