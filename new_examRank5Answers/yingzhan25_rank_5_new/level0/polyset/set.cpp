#include "set.hpp"

set::set() : _bag(0) {}

set::set(searchable_bag& bag) : _bag(&bag) {}

set::set(searchable_bag* bag) : _bag(bag) {}

set::set(const set& other): _bag(0) 
{
    if (other._bag != 0)
        _bag = other._bag;
}

set&    set::operator=(const set& other)
{
    if (this != &other)
        _bag = other._bag;
    return (*this);
}

set::~set() {}

void    set::insert(int num)
{
    if (_bag == 0)
        return ;
    if (!_bag->has(num))
        _bag->insert(num);
}

void    set::insert(int *data, int count)
{
    if (_bag == 0 || data == 0 || count <= 0)
        return ;
    for (int i = 0; i < count; i++)
    {
        if (!_bag->has(data[i]))
            _bag->insert(data[i]);
    }
}

void    set::print() const
{
    if (_bag == 0)
        return ;
    _bag->print();
}

void    set::clear()
{
    if (_bag == 0)
        return ;
    _bag->clear();
}

bool    set::has(int num)const
{
    if (_bag == 0)
        return (false);
    return (_bag->has(num));
}