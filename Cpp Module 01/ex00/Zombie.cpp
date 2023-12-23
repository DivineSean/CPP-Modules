#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << this->name + ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    this->name = "Default";
    announce();
}

Zombie::Zombie( std::string name )
{
    this->name = name;
    announce();
}

Zombie::~Zombie()
{
    std::cout << this->name + ": " << "Destroyed" << std::endl;
}