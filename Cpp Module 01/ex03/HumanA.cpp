#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << this->Weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, class Weapon &Weapon) :name(name), Weapon(Weapon)
{
}

HumanA::~HumanA()
{
}