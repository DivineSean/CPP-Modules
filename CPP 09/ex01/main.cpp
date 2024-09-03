#include "RPN.hpp"

int main(int ac, char **av){

    if (ac != 2)
    {
        std::cerr << "The Program Can Only Take One Argument." << std::endl;
        return 1;
    }
    RPN R;
    R.FillingStack(av[1]);
    return 0;
}