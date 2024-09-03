#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

#include <iomanip> // For std::fixed and std::setprecision

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
    public:
    	BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		BitcoinExchange & operator=(BitcoinExchange const & copy);
        void    execute(std::string File);
		~BitcoinExchange();
};