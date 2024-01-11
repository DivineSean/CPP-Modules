#include "ClapTrap.hpp"

int main()
{
    ClapTrap Player1( "BOB" );
    ClapTrap Player2( "Timmy" );

    Player1.attack( "Npcs" );
    Player1.takeDamage ( 5 );
    Player1.beRepaired ( 4 ) ;
    
    Player2.attack( "Npcs" );
    Player2.takeDamage( 8 );
    Player2.beRepaired( 2 );

    return (0);
}