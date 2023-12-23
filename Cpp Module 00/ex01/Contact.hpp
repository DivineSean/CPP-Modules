#ifndef CONTACT_HPP
#define CONTACT_HPP
# include "PhoneBook.hpp"

class Contact
{
    private:
        std::string First_Name;
        std::string Last_Name;
        std::string Nickname;
        std::string Phone_Number;
        std::string Dark_Secret;
    public:
        Contact();
        void    set_contact(std::string str, int i);
        void    print_fullcontact() const;
        void    print_contact(int i) const;
        ~Contact();
};
#endif