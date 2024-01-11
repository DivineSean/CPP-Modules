#include "FragTrap.hpp"

int main()
{
    FragTrap Player1( "BOB" );
    FragTrap Player2( "Timmy" );

    Player1.attack( "Npcs" );
    Player1.takeDamage ( 35 );
    Player1.beRepaired ( 17 ) ;
    Player1.highFivesGuys();
    
    Player2.attack( "Npcs" );
    Player2.takeDamage( 11 );
    Player2.beRepaired( 2 );
    Player2.highFivesGuys();

    return (0);
}