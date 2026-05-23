#include "set.hpp"

set::set(searchable_bag &bag) : _bag(&bag) {}

set::~set() {}

const searchable_bag &set::get_bag()
{
	return *this->_bag;
}

void	set::insert(int value)
{
	if (!this->_bag->has(value))
		this->_bag->insert(value);
}

void	set::insert(int *data, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!this->_bag->has(data[i]))
			this->_bag->insert(data[i]);
	}
}

void	set::print() const
{
	this->_bag->print();
}

void	set::clear()
{
	this->_bag->clear();
}

bool	set::has(int value) const
{
	return (this->_bag->has(value));
}