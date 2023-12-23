#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
    public:
        PhoneBook(/* args */);
        void    add_contact(Contact contact, int *i);
        void    get_info(int i)  const;
        ~PhoneBook();
};

std::string read_Myline(std::string str);