#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Default Cat Constructor Called" << std::endl;
}

Cat::Cat( std::string type ) : type(type)
{
    std::cout << type << " Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Copy Cat Constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=( const Cat &copy )
{
    this->type = copy.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow Moew Meow" << std::endl;
}

std::string Cat::getType() const
{
    return (this->type);
}

Cat::~Cat()
{
    std::cout << "Cat Deconstructor called" << std::endl;
}