#include "vect2.hpp"

vect2::vect2() : _x(0) , _y(0) {}

vect2::vect2(int x, int y) : _x(x) , _y(y) {}

vect2::vect2(const vect2 &copy) : _x(copy._x) , _y(copy._y) {}

vect2	&vect2::operator=(const vect2 &copy)
{
	if (this != &copy)
	{
		this->_x = copy._x;
		this->_y = copy._y;
	}
	return *this;
}

vect2::~vect2() {}

// --------------------- [ ] ---------------------

int	&vect2::operator[](int i)
{
	if (i == 0)
		return this->_x;
	return this->_y;
}

int	vect2::operator[](int i) const
{
	if (i == 0)
		return this->_x;
	return this->_y;
}

// --------------------- [ ] ---------------------

// --------------------- addition ---------------------

vect2	vect2::operator+(const vect2 &other) const
{
	vect2	temp;
	temp._x = this->_x + other._x;
	temp._y = this->_y + other._y;
	return temp;
}

vect2	&vect2::operator+=(const vect2 &other)
{
	*this = *this + other;
	return *this;
}

// --------------------- addition ---------------------

// --------------------- subtraction ---------------------

vect2	vect2::operator-() const
{
	vect2	temp;
	temp._x = -this->_x;
	temp._y = -this->_y;
	return temp;
}

vect2	vect2::operator-(const vect2 &other) const
{
	vect2	temp;
	temp._x = this->_x - other._x;
	temp._y = this->_y - other._y;
	return temp;
}

vect2	&vect2::operator-=(const vect2 &other)
{
	*this = *this - other;
	return *this;
}

// --------------------- subtraction ---------------------

// --------------------- multiplication ---------------------

vect2	vect2::operator*(int i) const
{
	vect2	temp;
	temp._x = this->_x * i;
	temp._y = this->_y * i;
	return temp;
}

vect2	&vect2::operator*=(int i)
{
	*this = *this * i;
	return *this;
}

// --------------------- multiplication ---------------------

// --------------------- increment decrement ---------------------

vect2	&vect2::operator++()
{
	*this += vect2(1, 1);
	return *this;
}

vect2	vect2::operator++(int)
{
	vect2	temp(*this);
	*this += vect2(1, 1);
	return temp;
}

vect2	&vect2::operator--()
{
	*this -= vect2(1, 1);
	return *this;
}

vect2	vect2::operator--(int)
{
	vect2	temp(*this);
	*this -= vect2(1, 1);
	return temp;
}

// --------------------- increment decrement ---------------------

// --------------------- comparative operators ---------------------

bool	vect2::operator==(const vect2 &other) const
{
	if (this->_x == other._x && this->_y == other._y)
		return true;
	return false;
}

bool	vect2::operator!=(const vect2 &other) const
{
	if (this->_x != other._x && this->_y != other._y)
		return true;
	return false;
}

// --------------------- comparative operators ---------------------

vect2	operator*(int i, const vect2 &other)
{
	vect2	temp;
	temp = other * i;
	return temp;
}

std::ostream	&operator<<(std::ostream &os, const vect2 &other)
{
	os << "{" << other[0] << ", " << other[1] << "}";
	return os;
}
