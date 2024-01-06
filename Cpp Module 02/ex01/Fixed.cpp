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

Fixed::Fixed( const int Fixed_Point ) : Fixed_Point(Fixed_Point << Fractional_Bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float FF )
{
    std::cout << "Float constructor called" << std::endl;
    Fixed_Point = roundf(FF * (1 << Fractional_Bits));
}

int Fixed::getRawBits() const
{
    return (this->Fixed_Point);
}

void    Fixed::setRawBits( int const raw )
{
    this->Fixed_Point = raw;
}


Fixed &Fixed::operator= (const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->setRawBits(copy.getRawBits());
    return (*this);
}

std::ostream &operator<< (std::ostream &os, const Fixed &Float)
{
    os << Float.toFloat();
    return (os);
}

float Fixed::toFloat() const
{
    return ((float)Fixed_Point / (float)(1 << Fractional_Bits));
}

int   Fixed::toInt() const
{
    return (Fixed_Point / (1 << Fractional_Bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}