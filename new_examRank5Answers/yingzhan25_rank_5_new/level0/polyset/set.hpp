#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class searchable_bag;

class set
{
    private:
        searchable_bag  *_bag;
    
    public:
        set();
        set(searchable_bag& bag);
        set(searchable_bag* bag);
        set(const set& other);
        set&    operator=(const set& other);
        ~set();

        void    insert(int num);
        void    insert(int *data, int count);
        void    print() const;
        void    clear();
        bool    has(int num)const;
};

#endif