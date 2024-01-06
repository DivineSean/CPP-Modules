#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point( float x, float y ) : x(x), y(y)
{
}

Point::Point( const Point &copy)
{
    *this = copy;
}

Point &Point::operator= (const Point &copy)
{
    if (this == &copy)
        return (*this);
    const_cast<Fixed &>(x) = const_cast<Fixed &> (copy.x);
    const_cast<Fixed &>(y) = const_cast<Fixed &> (copy.y);
    return (*this);
}

Fixed    Point::getX() const
{
    return (this->x);
}

Fixed    Point::getY() const
{
    return (this->y);
}

Point::~Point()
{
}