#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default Dog Constructor Called" << std::endl;
}

Dog::Dog( std::string type ) : type(type)
{
    std::cout << type << " Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Copy Dog Constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=( const Dog &copy )
{
    this->type = copy.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}

Dog::~Dog()
{
    std::cout << "Dog Deconstructor called" << std::endl;
}