#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Test", 120);
        Bureaucrat a(b);
        
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.decrement();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}