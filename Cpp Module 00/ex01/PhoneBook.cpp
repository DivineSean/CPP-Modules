#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{

}

PhoneBook::~PhoneBook()
{

}

int isdegit(std::string str, int *r)
{
    int i;
    size_t num;

    i = 0;
    num = 0;
    if (str.empty())
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '7')
            return (0);
        num = (num * 10) + (str[i] - 48);
        i++;
    }
    if (num >= 0 && num <= 7)
    {
        *r = (int)num;
        return (1);
    }
    return (0);
}

void    PhoneBook::get_info(int len) const
{
    std::string str;
    int         num;
    int         i = 0;

    while (i < len)
    {
        contact[i].print_contact(i);
        std::cout << " ---------" << "----------" << "----------" << "----------" << "----"  << std::endl;
        i++;
    }
    while (str != "BACK" && !isdegit(str, &num))
        str = read_Myline("* Please select index [0-7] * OR * Use BACK to quit SEARCH MODE *\nindex >> ");
    if (str != "BACK")
        contact[num].print_fullcontact();
}

void    PhoneBook::add_contact(Contact c, int *j)
{
    static int i;

    if (i >= 8)
        i = 0;
    if (*j >= 7)
        *j = 7;
    contact[i] = c;
    i++;
    (*j)++;
}