#include "ScavTrap.hpp"

int main()
{
    ScavTrap Player1( "BOB" );
    ScavTrap Player2( "Timmy" );

    Player1.attack( "Npcs" );
    Player1.takeDamage ( 35 );
    Player1.beRepaired ( 17 ) ;
    Player1.guardGate();
    
    Player2.attack( "Npcs" );
    Player2.takeDamage( 11 );
    Player2.beRepaired( 2 );
    Player2.guardGate();

    return (0);
}