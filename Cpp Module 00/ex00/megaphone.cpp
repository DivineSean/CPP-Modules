#include <iostream>
#include <string>
#include <cctype>

void    av_up(std::string str)
{
    int len = str.size();

    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = std::toupper(str[i]);
    }
    std::cout << str;
}

int main(int ac, char **av)
{
    std::string str;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i <= ac - 1; i++)
    {
        str = av[i];
        av_up(str);
    }
    std::cout << std::endl;
    return (0);
}