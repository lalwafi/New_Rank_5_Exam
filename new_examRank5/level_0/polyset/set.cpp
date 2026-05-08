#include "set.hpp"

set::set(searchable_bag &bag) : _bag(&bag) {}

set::set(const set &copy) : _bag(copy._bag) {}

set	&set::operator=(const set &copy)
{
	if (this != &copy)
		_bag = copy._bag;
	return *this;
}

set::~set() {}

const searchable_bag	&set::get_bag()
{
	return *_bag;
}

void	set::insert(int value)
{
	if (!(_bag->has(value)))
		_bag->insert(value);
}

void	set::insert(int *data, int i)
{
	for (int j = 0; j < i; j++)
	{
		if (!(_bag->has(data[j])))
			_bag->insert(data[j]);
	}
}

void	set::print() const
{
	_bag->print();
}

void	set::clear()
{
	_bag->clear();
}

bool	set::has(int value) const
{
	return (_bag->has(value));
}
