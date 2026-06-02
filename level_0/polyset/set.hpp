#pragma once
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag *_bag;
		set();
		set(const set &copy);
		set	&operator=(const set &copy);

	public:
		set(searchable_bag &bag);
		virtual ~set();

		const searchable_bag& get_bag();

		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();

		bool has(int) const;
};