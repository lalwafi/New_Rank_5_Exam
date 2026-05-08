#include "set.hpp"

set::set(searchable_bag &_bag):bag(&_bag)
{}

set::~set()
{}
set::set(const set& copy):bag(copy.bag)
{
}

set& set::operator=(const set& assign)
{
    if (this != &assign)
        bag = assign.bag;

        return (*this);
}

const searchable_bag& set::get_bag()
{
	return(*bag);
}                  

void set::insert (int value)
{
    if (!(bag->has(value)))
        bag->insert(value);
}

 void set::insert (int *data, int i)
 {
    for (int j = 0; j < i; j++)
    {
        if (!bag->has(data[j]))
            bag->insert(data[j]);
    }
 }

void set::print() const
{
    bag->print();
}

void set::clear()
{
    bag->clear();
}

bool set::has(int value) const
{
    return(bag->has(value));
}