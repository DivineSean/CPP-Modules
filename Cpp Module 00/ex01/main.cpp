#include "PhoneBook.hpp"

std::string strtrim(const std::string &str)
{
    std::string trimmed = str;
    size_t start = 0;
    while (start < trimmed.length() && std::isspace(trimmed[start]))
        start++;
    trimmed = trimmed.substr(start);
    size_t end = trimmed.length() - 1;
    while (end > 0 && std::isspace(trimmed[end]))
        end--;
    trimmed = trimmed.substr(0, end + 1);
    return trimmed;
}

std::string read_Myline(std::string c)
{
    std::string str;

    while(1)
    {
        std::cout << c;
        getline(std::cin, str);
        str = strtrim(str);
        if (std::cin.eof() == 1)
        {
            std::cin.clear();
            rewind(stdin);
            std::cout << std::endl;
        }
        else if (str.empty() && c != "Prompt Command >> " && c != "* Please select index [0-7] * OR * Use BACK to quit SEARCH MODE *\nindex >> ")
            std::cout << "Contact " + c.substr(0, c.size()-2) << " Must be not Empty!!" << std::endl ;
        else
            break;
    }
    return (str);
}

PhoneBook Add_Contact(PhoneBook Phone, int *i)
{
    std::string str;
    Contact contact;
    str = read_Myline("First Name: ");
    contact.set_contact(str, 0);
    str = read_Myline("Last Name: ");
    contact.set_contact(str, 1);
    str = read_Myline("Nickname: ");
    contact.set_contact(str, 2);
    str = read_Myline("Phone Number: ");
    contact.set_contact(str, 3);
    str = read_Myline("Dark Secret: ");
    contact.set_contact(str, 4);
    Phone.add_contact(contact, i);
    return (Phone);
}

void    Search_Phone(PhoneBook Phone, int i)
{
    std::string str;

    std::cout << " ---------" << "----------" << "----------" << "----------" << "----"  << std::endl;
    std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << " ---------" << "----------" << "----------" << "----------" << "----"  << std::endl;
    Phone.get_info(i);
}

int main()
{
    int i = 0;
    PhoneBook   Phone;
    std::string str;
 
    std::cout << "* Welcome To PhoneBook *" << std::endl;
    std::cout << "Available Commands | ADD | SEARCH | EXIT |" << std::endl;
    while(1)
    {
        str = read_Myline("Prompt Command >> ");
        if (str == "ADD")
            Phone = Add_Contact(Phone, &i);
        else if (str == "SEARCH")
            Search_Phone(Phone, i);
        else if (str == "EXIT")
            break ;
        else if (!str.empty())
            std::cout << "Available Command are | ADD | SEARCH | EXIT" << std::endl;
    }
    return (0);
}