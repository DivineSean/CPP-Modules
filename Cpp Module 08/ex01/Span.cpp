#include "Span.hpp"

Span::Span(unsigned int n)
{
    if (n > INT_MAX)
        throw MaxSizeProtection();
    std::cout << "Constructor Called To Set " << n << " Max Storage Number" << std::endl;
    Max = n;
}

Span::Span( Span const &copy)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
}

Span &Span::operator=(const Span &copy)
{
    if (this == &copy)
        return(*this);
    this->Max = copy.Max;
    this->_Span.clear();
    this->_Span = copy._Span;
    return(*this);
}

char const *Span::MaxSizeProtection::what() const throw()
{
    return("The Maximum Storage provide is either a lot or negative value");
}

char const *Span::MaxStorageSpan::what() const throw()
{
    return("The Span already Reached The Maximum Storage. Cannot Add More Integers");
}

char const *Span::SupportOnlyInt::what() const throw()
{
    return("addNumber Methode Support Only Integers");
}

char const *Span::VectorNoRange::what() const throw()
{
    return("Range cant be found If there are no numbers stored, or only one, no span can be found.");
}

void    Span::addNumber(long long n)
{
    if (n > INT_MAX || n < INT_MIN)
        throw SupportOnlyInt();
    if (_Span.size() > Max)
        throw MaxStorageSpan();
    _Span.push_back(n);
}

void    Span::addManyNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end)
{
    if (_Span.size() > Max)
        throw MaxStorageSpan();
    _Span.insert(_Span.end(), it_begin, it_end);
    if (_Span.size() > Max)
        throw MaxStorageSpan();
}

int    Span::longestSpan() const
{
    if (_Span.size() < 2)
        throw VectorNoRange();
    int min = *std::min_element(_Span.begin(), _Span.end());
    int max = *std::max_element(_Span.begin(), _Span.end());
    return (abs(max-min));
}

int Span::shortestSpan()
{
    if (_Span.size() < 2)
        throw VectorNoRange();
    std::sort(_Span.begin(), _Span.end());
    size_t i = 0;
    int min = abs(_Span[1] - _Span[0]);
    while(i < _Span.size() - 1)
    {
        if (min > abs(_Span[i] - _Span[i + 1]))
            min = abs(_Span[i] - _Span[i + 1]);
        i++;
    }
    return (min);
}

Span::~Span()
{
    std::cout << "Destructor Called For Span." << std::endl;
}