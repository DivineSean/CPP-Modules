#include "Serialization.hpp"

Serializer::Serializer()
{
    std::cout << "Constructor Called." << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
    if (this == &copy)
        return (*this);
    return (*this);
}

Serializer::Serializer( Serializer const &copy )
{
    std::cout << "Copy Constructor Called " << std::endl;
    *this = copy;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t u = reinterpret_cast<uintptr_t>(ptr);
    return (u);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *t = reinterpret_cast<Data *>(raw);
    return (t);
}

Serializer::~Serializer()
{
    std::cout << "Destructor Called." << std::endl;
}
