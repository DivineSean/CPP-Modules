#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default Constructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this == &copy)
        return (*this);
    return (*this);
}

bool    isChar(char c)
{
    return (c < '0' || c > '9');
}

bool    inputCheck(std::string s)
{
    int i = 0;
    if (!s[0])
        return (false);
    while(s[i])
    {
        if (!std::isprint(s[i]))
            return (false);
        i++;
    }
    return (true);
}

bool    isFloat(std::string s)
{
    if (s.find(".") != std::string::npos && s.find("f") != std::string::npos && s[s.length() - 1] == 'f' && s.find("+.") == std::string::npos && s.find ("-.") == std::string::npos)
    {
        int i = 0;
        int comma = 0;
        int f = 0;
        if (s[0] == '+' || s[0] == '-')
            i++;
        while(s[i] && comma <= 1 && f <= 1)
        {
            if (s[i] == '.')
                comma++;
            else if (s[i] == 'f')
                f++;
            else if (s[i] > '9' || s[i] < '0')
                return (false);
            i++;
        }
        if (comma == 1 && f == 1 && s[0] != '.' && s.find(".f") == std::string::npos && s.find("f.") == std::string::npos)
            return (true);
    }
    return (false);
}

bool    isInt(std::string s)
{
    int i = 0;

    if (s[0] == '+' || s[0] == '-')
        i++;
    while(s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

bool    isDouble(std::string s)
{
    if (s.find(".") != std::string::npos && s.find("+.") == std::string::npos && s.find ("-.") == std::string::npos)
    {
        int i = 0;
        int comma = 0;
        if (s[0] == '+' || s[0] == '-')
            i++;
        while(s[i] && comma <= 1)
        {
            if (s[i] == '.')
                comma++;
            else if (s[i] > '9' || s[i] < '0')
                return (false);
            i++;
        }
        if (comma == 1 && s[0] != '.' && s[s.length() - 1] != '.')
            return (true);
    }
    return (false);
}

std::string getType(std::string s)
{
    std::string type[4] = {"char", "int", "float", "double"};
    if (inputCheck(s))
    {
        if (s.length() == 1 && isChar(s[0]))
            return (type[0]);
        else if (isInt(s))
            return (type[1]);
        else if (isFloat(s) || s == "-inff" || s == "+inff" || s == "nanf")
            return (type[2]);
        else if (isDouble(s) || s == "-inf" || s == "+inf" || s == "nan")
            return (type[3]);
        return "Impossible";
    }
    return "Non Printable";
}

double power(int index)
{
    double result = 1;
    int i = 0;
    while(i < index)
    {
        result *=10;
        i++;
    }
    return (result);
}

double ToDouble(std::string s)
{
    int i = 0;
    double res = 0;
    int j = 0;
    int sign = 1;
    if (s[0] == '+' || s[0] == '-')
    {
        if (s[0] == '-')
            sign = -1;
        i++;
    }
    while(s[i] && s[i] != 'f')
    {
        if (s[i] != '.')
            res = (res * 10) + (s[i] - '0');
        else
            j = i;
        i++;
    }
    if (j != 0)
    {
        int size;
        if (s[i] == 'f')
            size = (s.length() - 2) - j;
        else
            size = (s.length() - 1) - j;
        res /= (power(size));
    }
    return (res * sign);
}

void    ft_nf(std::string s)
{
        if (s == "-inff" || s == "-inf")
        {
            std::cout << "char : Impossible" << std::endl;
            std::cout << "int : Impossible" << std::endl;
            std::cout << "float : -inff" << std::endl;
            std::cout << "double : -inf" << std::endl;
        }
        else if (s == "+inff" || s == "+inf")
        {
            std::cout << "char : Impossible" << std::endl;
            std::cout << "int : Impossible" << std::endl;
            std::cout << "float : +inff" << std::endl;
            std::cout << "double : +inf" << std::endl;
        }
        else if (s == "nanf" || s == "nan")
        {
            std::cout << "char : Impossible" << std::endl;
            std::cout << "int : Impossible" << std::endl;
            std::cout << "float : nanf" << std::endl;
            std::cout << "double : nan" << std::endl;
        }
}

void ScalarConverter::convert(std::string s)
{
    std::string type = getType(s);
    double      res = 0;
    if (type == "Non Printable")
    {
        std::cerr << "Non Printable Caractere Has Been Given in Input." << std::endl;
        exit(1);
    }
    else if (type == "Impossible")
    {
        std::cout << "char : Impossible" << std::endl;
        std::cout << "int : Impossible" << std::endl;
        std::cout << "float : Impossible" << std::endl;
        std::cout << "double : Impossible" << std::endl;
    }
    else if (type == "char")
    {
        std::cout << "char : " << s << std::endl;
        std::cout << "int : " << static_cast<int>(s[0]) << std::endl;
        std::cout << "float : " << static_cast<float>(s[0]) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(s[0]) << ".0" << std::endl;
    }
    else if (type == "int")
    {
        res = ToDouble(s);
        if (std::isprint(res) && (static_cast<long>(res) == res))
            std::cout << "char : '" << static_cast<char>(res) << "'" << std::endl;
        else
            std::cout << "char : " << "Non displayable" << std::endl;
        std::cout << "int : " << res << std::endl;
        std::cout << "float : " << res << ".0f" << std::endl;
        std::cout << "double : " << res << ".0" << std::endl;
    }
    else if (type == "float")
    {
        res = ToDouble(s);
        if (s == "-inff" || s == "+inff" || s == "nanf")
        {
            ft_nf(s);
            return;
        }
        if (std::isprint(res) && (static_cast<long>(res) == res))
            std::cout << "char : '" << static_cast<char>(res) << "'" << std::endl;
        else
            std::cout << "char : " << "Non displayable" << std::endl;
        if (res < INT_MIN || res > INT_MAX)
            std::cout << "int :" << "impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(res) << std::endl;
        if (abs(res) - static_cast<int>(abs(res)) > 0)
        {
            std::cout << "float : " << static_cast<float>(res) << "f" << std::endl;
            std::cout << "double : " << static_cast<double>(res) << std::endl;
        }
        else
        {
            std::cout << "float : " << static_cast<float>(res) << ".0f" << std::endl;
            std::cout << "double : " << static_cast<double>(res) << ".0" << std::endl;
        }
    }
    else if (type == "double")
    {
        res = ToDouble(s);
        if (s == "-inf" || s == "+inf" || s == "nan")
        {
            ft_nf(s);
            return;
        }
        if (std::isprint(res) && (static_cast<long>(res) == res))
            std::cout << "char : '" << static_cast<char>(res) << "'" << std::endl;
        else
            std::cout << "char : " << "Non displayable" << std::endl;
        if (res < INT_MIN || res > INT_MAX)
            std::cout << "int :" << "impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(res) << std::endl;
        if (abs(res) - static_cast<int>(abs(res)) > 0)
        {
            std::cout << "float : " << static_cast<float>(res) << "f" << std::endl;
            std::cout << "double : " << static_cast<double>(res) << std::endl;
        }
        else
        {
            std::cout << "float : " << static_cast<float>(res) << ".0f" << std::endl;
            std::cout << "double : " << static_cast<double>(res) << ".0" << std::endl;
        }
    }
}

ScalarConverter::ScalarConverter( ScalarConverter const &copy )
{
    std::cout << "Copy Constructor Called " << std::endl;
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor Called " << std::endl;
}