#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream myfile("data.csv");
    std::string line;
    std::string date, price;
    if (!myfile.is_open())
        throw std::runtime_error("Error: data.csv not found.");
    if (!std::getline(myfile, line))
        throw std::runtime_error("Error: data.csv is empty.");
    while (std::getline(myfile, line))
    {
        std::istringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, price, '\0');
        data[date] = std::strtod(price.c_str(), NULL);
    }
    myfile.close();
    return ; 
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this != &copy)
		this->data = copy.data;
	return *this;
}

bool is_other(std::string line)
{
    size_t i = 0;
    size_t len = 0;
    if (line.size() < 14)
        return true;
    if ((!(line[4] == '-' && line[7] == '-')) || (line[11] != '|') || line[10] != 32 || line[12] != 32)
        return true;
    while (line[i])
    {
        if (isalpha(line[i]) || (!isdigit(line[i]) && line[i] != '-' && line[i] != '|' && line[i] != 32 && line[i] != '.'))
            return true;
        if (line[i] == '.')
        {
            len++;
            if (i < 14)
                return true;
            if (len > 1)
                return (true);
        }
        i++;
    }
    if (line[i - 1] == '.')
        return true;
    return false;
}

bool check_current_data(std::string line, double &y, double &m, double &d, double &n)
{
    std::istringstream ss(line);
    std::string year, month, day, num;
    time_t now = time(NULL);
    tm *ltm = localtime(&now);

    getline(ss, year, '-');
    getline(ss, month, '-');
    getline(ss, day, ' ');
    getline(ss, num, ' ');
    getline(ss, num, ' ');
    y = std::strtod(year.c_str(), NULL);
    m = std::strtod(month.c_str(), NULL);
    d = std::strtod(day.c_str(), NULL);
    n = std::strtod(num.c_str(), NULL);
    if (y >= 1900 + ltm->tm_year)
    {
        if (y > 1900 + ltm->tm_year)
            return false;
        if (y >= 1900 + ltm->tm_year && m > 1 + ltm->tm_mon)
            return false;
        if (y >= 1900 + ltm->tm_year && m >= 1 + ltm->tm_mon && d > ltm->tm_mday)
            return false;
        return true;
    }
    return true;
}

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}

bool daysInMounth(int m)
{
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return true;
    }
    return false;
}

bool valid(std::string line, double &n, std::string &date)
{
    double y, m, d;
    std::istringstream ss(line);
    getline(ss, date, ' ');
    if (!check_current_data(line, y, m, d, n))
        return false;
    bool isLeap = 0;
    bool isThirtyOne = 0;
    if (isLeapYear(y))
        isLeap = 1;
    if (daysInMounth(m))
        isThirtyOne = 1;
    if (m <= 0 || m >= 13 || d <= 0 || d > 30 + isThirtyOne)
        return false;
    if (m == 2 && d > 28 + isLeap)
        return false;
    return true;
}

void    islineCorrect(std::string line, std::map<std::string, double> &data)
{
    std::istringstream ss(line);
    if (is_other(line))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    std::string date;
    double n;
    if (!valid(line, n, date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }
    if (n < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    if (n > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
    std::map<std::string, double>::iterator is_found = data.find(date);
    if (is_found != data.end())
        std::cout << date << " => " << n << " = " << n * (is_found)->second << std::endl;
    else
    {
        std::map<std::string, double>::iterator it_tmp = --data.upper_bound(date);
        if (date < data.begin()->first)
            std::cout << "Error: bad input => " << date << std::endl;
        else
            std::cout << date << " => " << n << " = " << n * it_tmp->second << std::endl;
    }
    return ;
}

std::string if_whitespaces(std::string line)
{
    size_t i = 0;
    size_t len;
    if (line[i] && ((line[i] >= 9 && line[i] <= 13) || line[i] == 32))
        throw 500;
    while(line[i])
    {
        len = 0;
        while (line[i + len] && ((line[i + len] >= 9 && line[i + len] <= 13) || line[i + len] == 32))
            len++;
        if (len > 1)
            throw 501;
        i++;
    }
    if (len)
        throw 502;
    return line;
}

void    BitcoinExchange::execute(std::string File)
{
    std::ifstream myfile(File);
    std::string line;
    if (!myfile.is_open())
        throw std::runtime_error("Error: File not found.");
    if (!std::getline(myfile, line))
    {
        myfile.close();
        throw std::runtime_error("Error: File is empty.");
    }
    else if (if_whitespaces(line) != "date | value")
    {
        myfile.close();
        throw std::runtime_error("Error: No 'date | value' found in the file.");
    }
    while (std::getline(myfile, line))
    {
        try {

            std::string s = if_whitespaces(line);
            islineCorrect(s, this->data);
        }
        catch (int x)
        {
            if (x == 500)
                std::cout << ("whitespaces detected in first of the line :Each line in this file must use the following format: 'date | value'.") << std::endl;
            else if (x == 501)
                std::cout << ("Multiple Spaces : Each line in this file must use the following format: 'date | value'.") << std::endl;
            else if (x == 502)
                std::cout << ("whitespaces detected in the end of the line :Each line in this file must use the following format: 'date | value'.") << std::endl;
        }
    }
    myfile.close();
    return ; 
}

BitcoinExchange::~BitcoinExchange()
{
}