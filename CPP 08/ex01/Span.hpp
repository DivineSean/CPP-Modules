#pragma once
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

class Span
{
    private:
        unsigned int Max;
        std::vector<int> _Span;
        Span();
    public:
        Span(unsigned int n);
        Span( Span const &copy);
        Span    &operator=(const Span &copy);
        void    addNumber(long long n);
        class   MaxSizeProtection : public std::exception
        {
            char const *what() const throw();
        };
        class   MaxStorageSpan : public std::exception
        {
            char const *what() const throw();
        };
        class   SupportOnlyInt : public std::exception
        {
            char const *what() const throw();
        };
        class   VectorNoRange : public std::exception
        {
            char const *what() const throw();
        };
        int     shortestSpan();
        int     longestSpan() const;
        void    addManyNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
        ~Span();
};