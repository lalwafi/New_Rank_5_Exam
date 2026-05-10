#include "vect2.hpp"

vect2::vect2() : _x(0) , _y(0) {}

vect2::vect2(int x, int y) : _x(x) , _y(y) {}

vect2::vect2(const vect2 &copy) : _x(copy._x) , _y(copy._y) {}

vect2	&vect2::operator=(const vect2 &copy)
{
	if (this != &copy)
	{
		_x = copy._x;
		_y = copy._y;
	}
	return *this;
}

vect2::~vect2() {}

// ---------------------- [ ] ----------------------

int	vect2::operator[](int i) const
{
	if (i == 0)
		return this->_x;
	return this->_y;
}

int	&vect2::operator[](int i)
{
	if (i == 0)
		return this->_x;
	return this->_y;
}

// ---------------------- [ ] ----------------------

// ---------------------- increment decrement ----------------------

vect2	&vect2::operator++()
{
	this->_x += 1;
	this->_y += 1;
	return *this;
}

vect2	vect2::operator++(int)
{
	vect2 temp(*this);
	this->_x += 1;
	this->_y += 1;
	return temp;
}

vect2	&vect2::operator--()
{
	this->_x -= 1;
	this->_y -= 1;
	return *this;
}

vect2	vect2::operator--(int)
{
	vect2 temp(*this);
	this->_x -= 1;
	this->_y -= 1;
	return temp;
}

// ---------------------- increment decrement ----------------------

// ---------------------- addition ----------------------

vect2	vect2::operator+(const vect2 &other) const
{
	vect2	temp(*this);
	temp._x += other._x;
	temp._y += other._y;
	return temp;
}

vect2	&vect2::operator+=(const vect2 &other)
{
	*this = *this + other;
	return *this;
}

// ---------------------- addition ----------------------

// ---------------------- subtraction ----------------------

vect2	vect2::operator-() const
{
	vect2	temp(*this);
	temp._x = -temp._x;
	temp._y = -temp._y;
	return temp;
}

vect2	vect2::operator-(const vect2 &other) const
{
	vect2	temp(*this);
	temp._x -= other._x;
	temp._y -= other._y;
	return temp;
}

vect2	&vect2::operator-=(const vect2 &other)
{
	*this = *this - other;
	return *this;
}

// ---------------------- subtraction ----------------------

// ---------------------- multiplication ----------------------

vect2	vect2::operator*(int i) const
{
	vect2	temp(*this);
	temp._x *= i;
	temp._y *= i;
	return temp;
}

vect2	&vect2::operator*=(int i)
{
	*this = *this * i;
	return *this;
}

vect2	operator*(int i, const vect2 &other)
{
	vect2	temp;
	temp = other * i;
	return temp;
}

// ---------------------- multiplication ----------------------

// ---------------------- compare ----------------------

bool	vect2::operator==(const vect2 &other) const
{
	return (this->_x == other._x && this->_y == other._y);
}

bool	vect2::operator!=(const vect2 &other) const
{
	return (this->_x != other._x && this->_y != other._y);
}

// ---------------------- compare ----------------------

std::ostream	&operator<<(std::ostream &os, const vect2 &other)
{
	os << "{" << other[0] << ", " << other[1] << "}";
	return os;
}
