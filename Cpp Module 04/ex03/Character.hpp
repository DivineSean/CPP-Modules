#pragma once

#include "ICharacter.hpp"
class Character : public ICharacter
{
    private:
        const std::string name;
        AMateria    *inventory[4];
    public:
        Character();
        Character(const std::string name);
        Character(const Character &copy);
        Character &operator=(const Character &copy);
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria *SelectToDrop(int idx) const;
        ~Character();
};