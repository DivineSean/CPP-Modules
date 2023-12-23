#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "That Program Takes one param!" << std::endl;
        return (1);
    }

    Harl    Harl_2_0;

    Harl_2_0.complain( av[1] );
    return (0);
}