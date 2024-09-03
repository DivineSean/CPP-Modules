#include "whatever.hpp"

int main()
{
    std::cout << "***************Testing Integers***************" << std::endl;
    {
        int a = 4;
        int b = 16;
        std::cout << "Before Swap : a = " << a << " and b = " << b << std::endl;
        swap<int>(a, b);
        std::cout << "after Swap : a = " << a << " and b = " << b << std::endl;
        std::cout << "The Max between a and b is : " << max<int>(a, b) << std::endl;
        std::cout << "The Min between a and b is : " << min<int>(a, b) << std::endl;
    }
    std::cout << "***************Testing Char***************" << std::endl;
    {
        char a = 'J';
        char b = 'K';
        std::cout << "Before Swap : a = " << a << " and b = " << b << std::endl;
        swap<char>(a, b);
        std::cout << "after Swap : a = " << a << " and b = " << b << std::endl;
        std::cout << "The Max between a and b is : " << max<char>(a, b) << std::endl;
        std::cout << "The Min between a and b is : " << min<char>(a, b) << std::endl;
    }
    std::cout << "***************Evaluator can test here***************" << std::endl;
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        return 0;
    }
    return 0;
}