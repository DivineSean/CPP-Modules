#include "PmergeMe.hpp"
int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "The Programme require Arguments." << std::endl;
        return 1;
    }
    PmergeMe FF(ac, av);
    return 0;
}