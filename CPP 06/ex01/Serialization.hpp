#pragma once
#include <iostream>

typedef struct t_vector
{
    int x;
    int y;
    int z;
}Data;

class Serializer
{
    private:
        Serializer();
    public:
        Serializer &operator=(const Serializer &copy);
        Serializer( Serializer const &copy );
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serializer();
};