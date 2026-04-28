#ifndef BAG_HPP
#define BAG_HPP

class bag
{
    public:
        virtual void    insert(int num) = 0;
        virtual void    insert(int *arr, int count) = 0;
        virtual void    print() const = 0;
        virtual void    clear() = 0;
};

#endif
