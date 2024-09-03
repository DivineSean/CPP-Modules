#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("b1", 149);
        
        std::cout << b << std::endl;
        
        Form a("f1", 150, 100);
        std::cout << a << std::endl;

        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}