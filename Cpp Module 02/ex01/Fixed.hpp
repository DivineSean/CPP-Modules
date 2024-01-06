#pragma once
# include <iostream>

class   Fixed
{
    private:
        int Fixed_Point;
        static const int Fractional_Bits;
    public:
        Fixed();
        Fixed( const Fixed &copy);
        Fixed( const int Fixed_Point);
        Fixed( const float FF);
        float toFloat() const;
        int   toInt() const;
        Fixed &operator= (const Fixed &copy);
        int   getRawBits() const;
        void  setRawBits( int const raw );
        ~Fixed();
};
std::ostream &operator<< (std::ostream &os, const Fixed &Float);