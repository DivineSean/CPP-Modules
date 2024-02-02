#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    protected:
        std::string type;
        Brain       *brain;
    public:
        Dog();
        Dog( std::string type );
        Dog( const Dog &copy );
        Dog &operator=(const Dog &copy);
        void makeSound() const;
        std::string getType() const;
        Brain       *getBrain() const;
        ~Dog();
};