#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog Constructor Called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog( std::string type ) : type(type)
{
    std::cout << type << " Dog Constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Copy Dog Constructor called" << std::endl;
    this->type = copy.getType();
    this->brain = new Brain(*(copy.getBrain()));
}

Dog &Dog::operator=( const Dog &copy )
{
    this->type = copy.getType();
    if (this->brain)
        delete (this->brain);
    this->brain = new Brain(*(copy.getBrain()));
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

Brain *Dog::getBrain() const
{
    return (this->brain);
}

Dog::~Dog()
{
    std::cout << "Dog Deconstructor called" << std::endl;
    delete (brain);
}