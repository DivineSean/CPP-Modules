#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    protected:
        std::string type;
        Brain       *brain;
    public:
        Cat();
        Cat( std::string type );
        Cat( const Cat &copy );
        Cat &operator=(const Cat &copy);
        void makeSound() const;
        std::string getType() const;
        Brain       *getBrain() const;
        ~Cat();
};