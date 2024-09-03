#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
template<typename T> void   easyfind(T &a, int b)
{
    if (a.size() == 0)
        throw std::invalid_argument("Empty Container");
    if (find(a.begin(), a.end(), b) != a.end())
        std::cout << "Element : " << b << " Found." << std::endl;
    else
        throw std::invalid_argument("We Cannot Found 2nd Argument in The Container");
}