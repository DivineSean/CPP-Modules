#include "Zombie.hpp"

int main()
{
    Zombie *y;
    
    y = newZombie( "Rachid" );
    if (!y)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (0);
    }
    randomChump( "Markik" );
    delete (y);
    return (0);
}