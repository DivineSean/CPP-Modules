#include "easyfind.hpp"

int main()
{
    std::vector<int> Numbers;
    int Value = 5;
    for (int i = 1; i <= 10; i++)
        Numbers.push_back(i);
    std::cout << "**Testing Valid Container And Valid Value**" << std::endl;
    try
    {
        easyfind(Numbers, Value);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "**Testing Valid Container And Valid Value That Is Not In The Container**" << std::endl;
    Value = -5;
    try
    {
        easyfind(Numbers, Value);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "**Testing Empty Container**" << std::endl;
    std::vector<int> num;
    Value = 4;
    try
    {
        easyfind(num, Value);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}