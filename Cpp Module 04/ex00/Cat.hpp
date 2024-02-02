#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
    protected:
        std::string type;
    public:
        Cat();
        Cat( std::string type );
        Cat( const Cat &copy );
        Cat &operator=(const Cat &copy);
        void makeSound() const;
        std::string getType() const;
        ~Cat();
};