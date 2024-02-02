#pragma once

#include "AMateria.hpp"
class Ice : public AMateria
{
    private:
        std::string type;
    public:
        Ice();
        Ice(const Ice &copy);
        Ice &operator=( const Ice &copy);
        std::string const &getType() const;
        Ice *clone() const;
        void use(ICharacter &target);
        ~Ice();
};