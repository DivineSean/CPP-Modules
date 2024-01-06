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
        Fixed &operator= (const Fixed &copy);
        int   getRawBits() const;
        void  setRawBits( int const raw );
        ~Fixed();
};