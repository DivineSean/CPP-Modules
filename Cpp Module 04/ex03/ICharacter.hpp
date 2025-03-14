#pragma once

#include <iostream>
#include "AMateria.hpp"
class AMateria;

class ICharacter
{
    protected:
        const std::string name;
    public:
        virtual ~ICharacter() {}
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual AMateria *SelectToDrop(int idx) const = 0;
};