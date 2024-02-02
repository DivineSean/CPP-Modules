#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default Animal Constructor Called" << std::endl;
}

Animal::Animal( std::string type ) : type(type)
{
    std::cout << type << " Animal Constructor called" << std::endl;
}

Animal::Animal( const Animal &copy )
{
    std::cout << "Copy Animal Constructor called" << std::endl;
    this->type = copy.type;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->type = copy.type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string    Animal::getType() const
{
    return (this->type);
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called" << std::endl;
}