#include "Point.hpp"
//Area A = [x1(y2 - y3) + x2(y3-y1) + x3(y1-y2)] / 2
Fixed   CalculArea(Point A, Point B, Point C)
{
    Fixed Area(((A.getX() * (B.getY() - C.getY())) + (B.getX() * (C.getY() - A.getY())) + (C.getX() * (A.getY() - B.getY()))) / 2);
    if (Area < 0)
        Area = Area * (-1);
    return (Area);
}

bool bsp( Point const A, Point const B, Point const C, Point const P)
{
    Fixed ABC = CalculArea(A, B, C);
    Fixed PBC = CalculArea(P, B, C);
    Fixed PAC = CalculArea(P, A, C);
    Fixed PAB = CalculArea(P, A, B);

    if (ABC == (PAB + PAC + PBC))
        return (true);
    return (false);
}