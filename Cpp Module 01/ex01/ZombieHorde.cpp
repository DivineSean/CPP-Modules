#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *H;

    if (N <= 0)
        return (NULL);
    H = new Zombie[N];
    if (!H)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++)
    {
        H[i].setName( name );
        H[i].announce();
    }
    return (H);
}