#pragma once
# include "Fixed.hpp"

class   Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point( const Point &copy );
        Point( const float x, const float y );
        Point &operator= (const Point &copy);
        Fixed    getX() const;
        Fixed    getY() const;
        ~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);