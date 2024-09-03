#include "Serialization.hpp"

int main() 
{
    Data d;

    d.x = 1;
    d.y = 2;
    d.z = 3;

    uintptr_t u = Serializer::serialize(&d);
    Data *t = Serializer::deserialize(u);

    std::cout << "x : " << t->x << "\ny : " << t->y << "\nz : " << t->z << std::endl;
    return 0;
}