#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point A(1,1);
    Point B(4,2);
    Point C(2,7);
    Point P(-2,3);

    if (bsp( A, B, C, P))
        std::cout << "This point is inside the triangle" << std::endl;
    else
        std::cout << "This Point is not inside the triangle" << std::endl;
    return (0);
}