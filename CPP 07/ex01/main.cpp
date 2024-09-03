#include "iter.hpp"

int main()
{
    std::cout << "***************Testing Integers***************" << std::endl;
    {
        int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << "Int Array Before Appling Inter Template : ";
        ::print_array(array, 10);
        std::cout << "Int Array After Appling Inter Template : ";
        ::iter(array, 10, increment);
        ::print_array(array, 10);
    }
    std::cout << "***************Testing Char***************" << std::endl;
    {
        char array[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        std::cout << "Int Array Before Appling Inter Template : ";
        ::print_array(array, 10);
        std::cout << "Int Array After Appling Inter Template : ";
        ::iter(array, 10, increment);
        ::print_array(array, 10);
    }
    std::cout << "***************Evaluator can test here***************" << std::endl;
    {
    }
    return 0;
}