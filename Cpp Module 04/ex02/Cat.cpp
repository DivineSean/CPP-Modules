#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Default Cat Constructor Called" << std::endl;
}

Cat::Cat( std::string type ) : type(type)
{
    brain = new Brain();
    std::cout << type << " Cat Constructor called" << std::endl;
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
    delete (brain);
    std::cout << "Cat Deconstructor called" << std::endl;
}