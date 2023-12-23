#include <iostream>

int main()
{
    std::string Var = "HI THIS IS BRAIN";
    std::string *stringPTR = &Var;
    std::string &stringREF = Var;

    std::cout << "The Memory address of the string Variable : " << &Var << std::endl;
    std::cout << "The Memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The Memory address held by stringREF : " << &stringREF << std::endl;

    std::cout << "The Value of the string variable : " << Var << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
}