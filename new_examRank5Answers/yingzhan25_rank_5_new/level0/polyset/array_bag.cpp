#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() : arr(0), size(0) {}
        
array_bag::array_bag(const array_bag& other)
{
    size = other.size;
    arr = new int[size];
    for (int i = 0;i < other.size; i++)
        arr[i] = other.arr[i];
}

array_bag&  array_bag::operator=(const array_bag& other)
{
    if (this == &other)
        return (*this);
    else
    {
        if (this->arr != 0)
        {
            delete[] this->arr;
            this->arr = 0;
        }
        this->size = other.size;
        this->arr = new int[size];
        for (int i = 0;i < other.size; i++)
            this->arr[i] = other.arr[i];
        return (*this);
    }
}

array_bag::~array_bag()
{
    if (arr != 0)
    {
        delete[] arr;
        arr = 0;
    }
}

void    array_bag::insert(int num)
{
    int *new_arr = new int[size + 1];
    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];
    new_arr[size] = num;
    if (arr != 0)
        delete[] arr;
    arr = new_arr;
    size++;
}

void    array_bag::insert(int *data, int count)
{
    int *new_arr = new int[size + count];
    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];
    for (int i = size; i < size + count; i++)
        new_arr[i] = data[i - size];
    if (arr != 0)
        delete[] arr;
    arr = new_arr;
    size += count;
}

void    array_bag::print() const
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void    array_bag::clear()
{
    if (arr != 0)
    {
        delete[] arr;
        arr = 0;
    }
    size = 0;
}