#pragma once
#include <iostream>

template<typename T> void    increment(T &a)
{
    a = a + 1;
}

template<typename T> void    print_array(T *array, size_t size)
{
    size_t i = 0;
    if (array == NULL || size == 0)
        return;
    while(i < size - 1)
        std::cout << array[i++] << ", ";
    std::cout << array[i] << std::endl;
    return;
}

template<typename T> void   iter(T *array, size_t size, void (*f)(T &))
{
    size_t i = 0;
    if (array == NULL || f == NULL || size == 0)
        return ;
    while(i < size)
        f(array[i++]);
    return;
}

template<typename T, typename F> void   iter(T *array, size_t size, F func)
{
    size_t i = 0;
    if (array == NULL || func == NULL || size == 0)
        return ;
    while(i < size)
        func(array[i++]);
    return;
}