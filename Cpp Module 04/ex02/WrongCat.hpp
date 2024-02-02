#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongCat();
        WrongCat( std::string type );
        WrongCat( const WrongCat &copy );
        WrongCat &operator=(const WrongCat &copy);
        void makeSound() const;
        std::string getType() const;
        ~WrongCat();
};