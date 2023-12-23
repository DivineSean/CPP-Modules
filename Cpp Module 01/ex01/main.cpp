#include "Zombie.hpp"

int main()
{
    Zombie *y;
    int     N ;

    N = 9;    
    y = zombieHorde(N, "Markik" );
    if (!y)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (0);
    }
    delete []y;
    return (0); 
}