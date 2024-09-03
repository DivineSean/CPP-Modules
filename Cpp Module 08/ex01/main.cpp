#include "Span.hpp"
#define size 20000
int main()
{
    try
    {
        Span sp = Span(size);
        std::vector<int> vec;
        srand(time(NULL));
        for(int i = 0; i < size; i++)
            vec.push_back(rand());

        sp.addManyNumber(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}