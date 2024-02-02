#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
    protected:
        std::string type;
    public:
        Dog();
        Dog( std::string type );
        Dog( const Dog &copy );
        Dog &operator=(const Dog &copy);
        void makeSound() const;
        std::string getType() const;
        ~Dog();
};