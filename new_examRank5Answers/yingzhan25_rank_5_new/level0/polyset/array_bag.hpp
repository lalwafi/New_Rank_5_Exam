#ifndef ARRAY_BAG_HPP
#define ARRAY_BAG_HPP

#include "bag.hpp"

class array_bag: virtual public bag
{
    protected:
        int *arr;
        int size;
    public:
        array_bag();
        array_bag(const array_bag& other);
        array_bag&  operator=(const array_bag& other);
        virtual ~array_bag();

        void    insert(int num);
        void    insert(int *data, int count);
        void    print() const;
        void    clear();
};

#endif