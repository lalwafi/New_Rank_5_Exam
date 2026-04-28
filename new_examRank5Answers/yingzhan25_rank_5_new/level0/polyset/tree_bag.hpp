#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP

#include "bag.hpp"

class tree_bag: virtual public bag
{
    protected:
        struct node
        {
            node *left;
            node *right;
            int value;
        };
        node    *tree;
    
    private:
        static node* copy_node(node* cur);
        static void    print_node(node* cur);
        static void    destroy_node(node* cur);
        
    public:
        tree_bag();
        tree_bag(const tree_bag& other);
        tree_bag&  operator=(const tree_bag& other);
        virtual ~tree_bag();

        void    insert(int num);
        void    insert(int *data, int count);
        void    print() const;
        void    clear();
};

#endif