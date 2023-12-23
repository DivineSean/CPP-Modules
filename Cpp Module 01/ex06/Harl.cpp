#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
};

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
};

void    Harl::error()
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
};

void    Harl::complain( std::string level )
{
    std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*String[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    size_t i;
    for (i = 0; i < 4; i++)
    {
        if (lvl[i] == level)
            break;
    }
    switch(i)
    {
        case 0: std::cout << "[ DEBUG ]" << std::endl; (this->*String[0])(); std::cout << std::endl;
        case 1: std::cout << "[ INFO ]" << std::endl; (this->*String[1])(); std::cout << std::endl;
        case 2: std::cout << "[ WARNING ]" << std::endl; (this->*String[2])(); std::cout << std::endl;
        case 3: std::cout << "[ ERROR ]" << std::endl; (this->*String[3])(); std::cout << std::endl; break;
        default: std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

Harl::Harl()
{
};

Harl::~Harl()
{
};