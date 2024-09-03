#pragma once
#include <iostream>
#include <deque>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        MutantStack() {
            std::cout << "MutantStack Constructor Called" << std::endl;
        };
        MutantStack(MutantStack const &copy) {
            std::cout << "Copy Constructor Called" << std::endl;
            *this = copy;
        };
        MutantStack &operator=(MutantStack const &copy) {
            std::cout << "Copy Assignement Called" << std::endl;
            if (*this == copy)
                return (*this);
            return (*this);
        };
        typename Container::iterator begin() {
            return(this->c.begin());
        };
        typename Container::iterator end() {
            return(this->c.end());
        };
        ~MutantStack() {
            std::cout << "MutantStack Destructor Called" << std::endl;
        };
};