#pragma once

#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
    protected:
        const std::string type;
    public:
        AMateria();
        AMateria(const AMateria &copy);
        AMateria(std::string const &type);
        virtual std::string const &getType() const; //Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter& target);
        virtual ~AMateria();
};