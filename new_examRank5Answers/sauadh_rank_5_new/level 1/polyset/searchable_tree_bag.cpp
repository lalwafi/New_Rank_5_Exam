#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag()
{
}

searchable_tree_bag::~searchable_tree_bag()
{}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& copy)
{
    *this = copy;
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& assign)
{
    if(this != &assign)
        tree_bag::operator=(assign);
    return (*this);
}

bool searchable_tree_bag::has(int value) const
{
    node *current = tree;
    while (current)
    {
        if (current->value == value)
            return (true);
        else if (current->value > value)
            current = current->l;
        else
            current = current->r;
    }
    return (false);
}