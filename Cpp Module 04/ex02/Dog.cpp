#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Default Dog Constructor Called" << std::endl;
}

Dog::Dog( std::string type ) : type(type)
{
    brain = new Brain();
    std::cout << type << " Dog Constructor called" << std::endl;
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
    delete (brain);
    std::cout << "Dog Deconstructor called" << std::endl;
}