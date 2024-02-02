#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default Cat Constructor Called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat( std::string type ) : type(type)
{
    std::cout << type << " Cat Constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Copy Cat Constructor called" << std::endl;
    this->type = copy.getType();
    this->brain = new Brain(*(copy.getBrain()));
}

Cat &Cat::operator=( const Cat &copy )
{
    this->type = copy.getType();
    if (this->brain)
        delete (this->brain);
    this->brain = new Brain(*(copy.getBrain()));
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

Brain *Cat::getBrain() const
{
    return (this->brain);
}

Cat::~Cat()
{
    std::cout << "Cat Deconstructor called" << std::endl;
    delete (brain);
}