#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "DEBUG!!" << std::endl;
};

void    Harl::info()
{
    std::cout << "INFO!!" << std::endl;
};

void    Harl::warning()
{
    std::cout << "WARNING!!" << std::endl;
};

void    Harl::error()
{
    std::cout << "ERROR!!" << std::endl;
};

void    Harl::complain( std::string level )
{
    std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*String[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (size_t i = 0; i < 4; i++)
    {
        if (lvl[i] == level)
        {
            (this->*String[i])();
            return ;
        }
    }
    std::cerr << "LEVEL PROTECTION!!" << std::endl;
}

Harl::Harl()
{
};

Harl::~Harl()
{
};