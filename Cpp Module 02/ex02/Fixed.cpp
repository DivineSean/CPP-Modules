#include "Fixed.hpp"

const int Fixed::Fractional_Bits = 8;

Fixed::Fixed() : Fixed_Point(0)
{
}

Fixed::Fixed( const Fixed &copy)
{
    *this = copy;
}

Fixed::Fixed( const int Fixed_Point ) : Fixed_Point(Fixed_Point << Fractional_Bits)
{
}

Fixed::Fixed( const float FF )
{
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
    if (this != &copy)
        this->setRawBits(copy.getRawBits());
    return (*this);
}

Fixed &Fixed::operator++ ()
{
    this->Fixed_Point++;
    return (*this);
}

Fixed Fixed::operator++ ( int )
{
    Fixed old = *this;
    this->Fixed_Point++;
    return (old);
}

Fixed &Fixed::operator-- ()
{
    this->Fixed_Point--;
    return (*this);
}

Fixed Fixed::operator-- ( int )
{
    Fixed old = *this;
    this->Fixed_Point--;
    return (old);
}

Fixed Fixed::operator+ (const Fixed &copy) const
{
    Fixed Total((this->toFloat() + copy.toFloat()));
    return (Total);
}

Fixed Fixed::operator- (const Fixed &copy) const
{
    Fixed Total((this->toFloat() - copy.toFloat()));
    return (Total);
}

Fixed Fixed::operator* (const Fixed &copy) const
{
    Fixed Total((this->toFloat() * copy.toFloat()));
    return (Total);
}

Fixed Fixed::operator/ (const Fixed &copy) const
{
    if (!copy.Fixed_Point)
    {
        Fixed Total(0);
        return (Total);
    }
    Fixed Total((this->toFloat() / copy.toFloat()));
    return (Total);
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

bool Fixed::operator> (const Fixed &copy) const
{
    if (this->toFloat() > copy.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator< (const Fixed &copy) const
{
    if (this->toFloat() < copy.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator>= (const Fixed &copy) const
{
    if (this->toFloat() >= copy.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator<= (const Fixed &copy) const
{
    if (this->toFloat() <= copy.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator== (const Fixed &copy) const
{
    if (this->toFloat() == copy.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator!= (const Fixed &copy) const
{
    if (this->toFloat() != copy.toFloat())
        return (true);
    return (false);
}

Fixed &Fixed::min( Fixed &copy, Fixed &copy1)
{
    if (copy.toFloat() < copy1.toFloat())
        return (copy);
    return (copy1);
}

const Fixed &Fixed::min( const Fixed &copy, const Fixed &copy1)
{
    if (copy.toFloat() < copy1.toFloat())
        return (copy);
    return (copy1);
}

Fixed &Fixed::max( Fixed &copy, Fixed &copy1)
{
    if (copy.toFloat() > copy1.toFloat())
        return (copy);
    return (copy1);
}

const Fixed &Fixed::max( const Fixed &copy, const Fixed &copy1)
{
    if (copy.toFloat() > copy1.toFloat())
        return (copy);
    return (copy1);
}

Fixed::~Fixed()
{
}