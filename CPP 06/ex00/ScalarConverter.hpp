#pragma once
#include <iostream>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter &operator=(const ScalarConverter &copy);
        ScalarConverter( ScalarConverter const &copy );
        static void convert(std::string s);
        ~ScalarConverter();
};
