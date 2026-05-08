#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(): array_bag()
{
}

searchable_array_bag::~searchable_array_bag()
{}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& copy)
{
    *this = copy;
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& assign)
{
    if(this != &assign)
        array_bag::operator=(assign);
    return (*this);
}

bool searchable_array_bag::has(int value) const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
            return (true);
    }
    return (false);
}