#include "HumanB.hpp"

void    HumanB::attack()
{
    if (!this->Weapon)
        std::cout << "There is nothing to attack with" << std::endl;
    else
        std::cout << name << " attacks with their " << this->Weapon->getType() << std::endl;
}

void    HumanB::setWeapon(class Weapon &Weapon)
{
    this->Weapon = &Weapon;
}

HumanB::HumanB(std::string name) :name(name)
{
    this->Weapon = NULL;
}

HumanB::~HumanB()
{
}