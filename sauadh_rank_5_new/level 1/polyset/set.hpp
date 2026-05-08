#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set{
 private:
    searchable_bag *bag;
 public:
    set(searchable_bag &bag);
    virtual ~set();
    set(const set& copy);
    const searchable_bag& get_bag();
    set& operator=(const set& assign);
    void insert (int);
	void insert (int *, int);
	void print() const;
	void clear();
    bool has(int) const;


};



#endif