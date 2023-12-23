#include "PhoneBook.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void Contact::set_contact(std::string str, int i)
{
    switch (i)
    {
        case 0:
            First_Name = str;
            break;
        case 1:
            Last_Name = str;
            break;
        case 2:
            Nickname = str;
            break;
        case 3:
            Phone_Number = str;
            break;
        case 4:
            Dark_Secret = str;
            break;
    }
}

std::string resize(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void Contact::print_fullcontact() const
{
    if (First_Name.empty())
    {
        std::cout << "Empty Index Pls select Non Empty index!!" << std::endl;
        return ;
    }
    std::cout << "First Name :" << First_Name << std::endl;
    std::cout << "Last Name :" << Last_Name << std::endl;
    std::cout << "Nickname :" << Nickname << std::endl;
    std::cout << "Phone_Number :" << Phone_Number << std::endl;
    std::cout << "Dark_Secret :" << Dark_Secret << std::endl;
}

void Contact::print_contact(int i) const
{
    std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << resize(First_Name) << "|" << std::setw(10) << resize(Last_Name) << "|" << std::setw(10) << resize(Nickname) << "|" << std::endl;
}