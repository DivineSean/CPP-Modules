#include "Fixed.hpp"

const int Fixed::Fractional_Bits = 8;

Fixed::Fixed() : Fixed_Point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        setRawBits(copy.getRawBits());
    return (*this);
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->Fixed_Point);
}

void    Fixed::setRawBits( int const raw )
{
    this->Fixed_Point = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}