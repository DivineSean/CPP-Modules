#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *Y;

    Y = new Zombie(name);
    return (Y);
}