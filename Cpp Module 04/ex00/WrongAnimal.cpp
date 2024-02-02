#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
    std::cout << type << " WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy )
{
    std::cout << "Copy WrongAnimal Constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    this->type = copy.type;
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string    WrongAnimal::getType() const
{
    return (this->type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Deconstructor called" << std::endl;
}