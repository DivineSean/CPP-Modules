#pragma once
#include <iostream>

template<typename T> class Array
{
    private:
        T            *array;
        unsigned int size;
    public:
        Array(): size(0)
        {
            std::cout << "Default Constructor Called." << std::endl;
            this->array = new T[size];
        }
        Array(unsigned int n): size(n)
        {
            std::cout << "Construction with an unsigned int " << size << " as a parameter Called" << std::endl;
            array = new T[size];
        }
        Array(const Array &copy)
        {
            std::cout << "Copy Constructor Called." << std::endl;
            if (this == &copy)
                return ;
            array = NULL;
            *this = copy;
        }
        Array &operator=(const Array &copy)
        {
            std::cout << "Operator= Called." << std::endl;
            if (array != NULL)
                delete[] array;
            this->size = copy.size;
            array = new T[size];
            unsigned int i = 0;
            while(i < size)
            {
                array[i] = copy.array[i];
                i++;
            }
            return (*this);
        }
        T &operator[](unsigned int index) const
        {
            //std::cout << "Operator[] Called" << std::endl;
            if (index >= size || array == NULL)
                throw Array<T>::IndexOutOfBoundsException();
            return (array[index]);
        }
        class IndexOutOfBoundsException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Exception:Index Was Out Of Bounds");
            }
        };
        unsigned int getSize() const
        {
            return (size);
        }
        ~Array()
        {
            std::cout << "Destructor with an unsigned int " << size << " as a parameter Called" << std::endl; 
            if (array != NULL)
                delete[] array;
        }
};