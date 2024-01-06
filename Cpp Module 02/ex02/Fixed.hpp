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
        Fixed &operator++ ();
        Fixed operator++ ( int );
        Fixed &operator-- ();
        Fixed operator-- ( int );
        Fixed operator+ (const Fixed &copy) const;
        Fixed operator- (const Fixed &copy) const;
        Fixed operator* (const Fixed &copy) const;
        Fixed operator/ (const Fixed &copy) const;
        bool operator> (const Fixed &copy) const;
        bool operator< (const Fixed &copy) const;
        bool operator>= (const Fixed &copy) const;
        bool operator<= (const Fixed &copy) const;
        bool operator== (const Fixed &copy) const;
        bool operator!= (const Fixed &copy) const;
        int   getRawBits() const;
        void  setRawBits( int const raw );
        static Fixed &min( Fixed &copy, Fixed &copy1);
        static const Fixed &min( const Fixed &copy, const Fixed &copy1);
        static Fixed &max( Fixed &copy, Fixed &copy1);
        static const Fixed &max( const Fixed &copy, const Fixed &copy1);
        ~Fixed();
};
std::ostream &operator<< (std::ostream &os, const Fixed &Float);