#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "Default WrongCat Constructor Called" << std::endl;
}

WrongCat::WrongCat( std::string type ) : type(type)
{
    std::cout << type << " WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "Copy WrongCat Constructor called" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=( const WrongCat &copy )
{
    this->type = copy.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Deconstructor called" << std::endl;
}